/*******************************************************************************


   Copyright (C) 2011-2014 SequoiaDB Ltd.

   This program is free software: you can redistribute it and/or modify
   it under the term of the GNU Affero General Public License, version 3,
   as published by the Free Software Foundation.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warrenty of
   MARCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU Affero General Public License for more details.

   You should have received a copy of the GNU Affero General Public License
   along with this program. If not, see <http://www.gnu.org/license/>.

   Source File Name = dmsCB.hpp

   Descriptive Name = Data Management Service Control Block Header

   When/how to use: this program may be used on binary and text-formatted
   versions of data management component. This file contains code logic for
   data management control block, which is the metatdata information for DMS
   component.

   Dependencies: N/A

   Restrictions: N/A

   Change Activity:
   defect Date        Who Description
   ====== =========== === ==============================================
          09/14/2012  TW  Initial Draft

   Last Changed =

*******************************************************************************/
#ifndef DMSCB_HPP_
#define DMSCB_HPP_

#include "core.hpp"
#include "oss.hpp"
#include "ossMem.hpp"
#include "dms.hpp"
#include "ossLatch.hpp"
#include "monDMS.hpp"
#include "dmsTempCB.hpp"
#include "ossAtomic.hpp"
#include "ossRWMutex.hpp"
#include "dpsLogWrapper.hpp"
#include "ossEvent.hpp"
#include "sdbInterface.hpp"
#include <map>
#include <set>


using namespace std ;

namespace engine
{
   class _pmdEDUCB ;
   class _dmsStorageUnit ;

   // for each collection space, there is one CSCB associate with it
   class _SDB_DMS_CSCB : public SDBObject
   {
   public:
      //ossSpinSLatch _mutex ;
      // maximum sequence id for the collection space
      // currently 1 sequence per collection space
      UINT32 _topSequence ;
      CHAR   _name [ DMS_COLLECTION_SPACE_NAME_SZ + 1 ] ;
      _dmsStorageUnit *_su ;
      _SDB_DMS_CSCB ( const CHAR *pName, UINT32 topSequence,
                      _dmsStorageUnit *su )
      {
         ossStrncpy ( _name, pName, DMS_COLLECTION_SPACE_NAME_SZ ) ;
         _name[DMS_COLLECTION_SPACE_NAME_SZ] = 0 ;
         _topSequence = topSequence ;
         _su = su ;
      }
      ~_SDB_DMS_CSCB () ;
   } ;
   typedef class _SDB_DMS_CSCB SDB_DMS_CSCB ;


   #define DMS_MAX_CS_NUM 4096
   #define DMS_INVALID_CS DMS_INVALID_SUID
   #define DMS_STATE_NORMAL  0
   #define DMS_STATE_BACKUP  1
   #define DMS_STATE_REBUILD 2
   #define DMS_CHANGESTATE_WAIT_LOOP 500

   /*
      _SDB_DMSCB define
   */
   class _SDB_DMSCB : public _IControlBlock
   {
   private :
   #ifdef DMSCB_XLOCK
   #undef DMSCB_XLOCK
   #endif
   #define DMSCB_XLOCK ossScopedLock _lock(&_mutex, EXCLUSIVE) ;
   #ifdef DMSCB_SLOCK
   #undef DMSCB_SLOCK
   #endif
   #define DMSCB_SLOCK ossScopedLock _lock(&_mutex, SHARED) ;

      ossSpinSLatch _mutex ;

      struct cmp_cscb
      {
         bool operator() (const char *a, const char *b)
         {
            return std::strcmp(a,b)<0 ;
         }
      } ;
      std::map<const CHAR*, dmsStorageUnitID, cmp_cscb> _cscbNameMap ;
      std::vector<SDB_DMS_CSCB*>          _cscbVec ;
      std::vector<SDB_DMS_CSCB*>          _delCscbVec ;
      std::vector<ossRWMutex*>            _latchVec ;
      std::vector<dmsStorageUnitID>       _freeList ;

      // represent the last page clean timestamp for a given storage unit
      typedef std::pair<ossTick,dmsStorageUnitID>  _pageCleanHistory ;
      // stores a list of page clean history
      std::list<_pageCleanHistory>                 _pageCleanHistoryList ;
      std::set<dmsStorageUnitID>                   _pageCleanHistorySet ;

      ossSpinXLatch           _stateMtx;
      ossEvent                _backEvent ;
      SINT64                  _writeCounter;
      UINT8                   _dmsCBState;
      UINT32                  _logicalSUID ;

      dmsTempCB               _tempCB ;

   private:
      void  _logCSCBNameMap () ;
      INT32 _CSCBNameInsert ( const CHAR *pName, UINT32 topSequence,
                              _dmsStorageUnit *su,
                              dmsStorageUnitID &suID ) ;
      INT32 _CSCBNameLookup ( const CHAR *pName,
                              SDB_DMS_CSCB **cscb ) ;
      INT32 _CSCBNameLookupAndLock ( const CHAR *pName,
                                     dmsStorageUnitID &suID,
                                     SDB_DMS_CSCB **cscb,
                                     OSS_LATCH_MODE lockType = SHARED,
                                     INT32 millisec = -1 ) ;
      void _CSCBRelease ( dmsStorageUnitID suID,
                          OSS_LATCH_MODE lockType = SHARED ) ;
      INT32 _CSCBNameRemove ( const CHAR *pName, _pmdEDUCB *cb,
                              SDB_DPSCB *dpsCB, SDB_DMS_CSCB *&pCSCB ) ;
      INT32 _CSCBNameRemoveP1 ( const CHAR *pName,
                                _pmdEDUCB *cb,
                                SDB_DPSCB *dpsCB ) ;
      INT32 _CSCBNameRemoveP1Cancel ( const CHAR *pName,
                                      _pmdEDUCB *cb,
                                      SDB_DPSCB *dpsCB ) ;
      INT32 _CSCBNameRemoveP2 ( const CHAR *pName,
                                _pmdEDUCB *cb,
                                SDB_DPSCB *dpsCB,
                                SDB_DMS_CSCB *&pCSCB ) ;
      void _CSCBNameMapCleanup () ;
      INT32 _joinPageCleanSU ( dmsStorageUnitID suID ) ;

      INT32 _delCollectionSpace ( const CHAR *pName, _pmdEDUCB *cb,
                                  SDB_DPSCB *dpsCB, BOOLEAN removeFile ) ;

   public:
      _SDB_DMSCB() ;
      virtual ~_SDB_DMSCB() ;

      virtual SDB_CB_TYPE cbType() const { return SDB_CB_DMS ; }
      virtual const CHAR* cbName() const { return "DMSCB" ; }

      virtual INT32  init () ;
      virtual INT32  active () ;
      virtual INT32  deactive () ;
      virtual INT32  fini () ;

      INT32 nameToSUAndLock ( const CHAR *pName, dmsStorageUnitID &suID,
                              _dmsStorageUnit **su,
                              OSS_LATCH_MODE lockType = SHARED,
                              INT32 millisec = -1 ) ;

      _dmsStorageUnit *suLock ( dmsStorageUnitID suID ) ;
      void suUnlock ( dmsStorageUnitID suID,
                      OSS_LATCH_MODE lockType = SHARED ) ;

      INT32 addCollectionSpace ( const CHAR *pName, UINT32 topSequence,
                                 _dmsStorageUnit *su, _pmdEDUCB *cb,
                                 SDB_DPSCB *dpsCB ) ;
      INT32 dropCollectionSpace ( const CHAR *pName, _pmdEDUCB *cb,
                                  SDB_DPSCB *dpsCB ) ;
      INT32 unloadCollectonSpace( const CHAR *pName, _pmdEDUCB *cb ) ;

      void dumpInfo ( std::set<monCollection> &collectionList,
                      BOOLEAN sys = FALSE ) ;
      void dumpInfo ( std::set<monCollectionSpace> &csList,
                      BOOLEAN sys = FALSE ) ;
      void dumpInfo ( std::set<monStorageUnit> &storageUnitList,
                      BOOLEAN sys = FALSE ) ;

      void dumpInfo ( INT64 &totalFileSize );

      dmsTempCB *getTempCB () ;

      INT32 dropCollectionSpaceP1 ( const CHAR *pName, _pmdEDUCB *cb,
                                    SDB_DPSCB *dpsCB );

      INT32 dropCollectionSpaceP1Cancel ( const CHAR *pName, _pmdEDUCB *cb,
                                          SDB_DPSCB *dpsCB );

      INT32 dropCollectionSpaceP2 ( const CHAR *pName, _pmdEDUCB *cb,
                                    SDB_DPSCB *dpsCB );

      _dmsStorageUnit *dispatchPageCleanSU ( dmsStorageUnitID *suID ) ;

      INT32 joinPageCleanSU ( dmsStorageUnitID suID ) ;

   public:
      typedef std::vector<SDB_DMS_CSCB*>::iterator CSCB_ITERATOR;

      OSS_INLINE CSCB_ITERATOR begin()
      {
         return _cscbVec.begin();
      }

      OSS_INLINE CSCB_ITERATOR end()
      {
         return _cscbVec.end();
      }

      INT32 writable( _pmdEDUCB * cb ) ;

      OSS_INLINE void writeDown()
      {
         _stateMtx.get();
         --_writeCounter;
         SDB_ASSERT( 0 <= _writeCounter, "write counter should not < 0" ) ;
         _stateMtx.release();
      }

      INT32 registerBackup() ;

      OSS_INLINE void backupDown()
      {
         _stateMtx.get() ;
         _dmsCBState = DMS_STATE_NORMAL ;
         _backEvent.signalAll() ;
         _stateMtx.release() ;
      }

      INT32 registerRebuild() ;

      OSS_INLINE void rebuildDown()
      {
         _stateMtx.get();
         _dmsCBState = DMS_STATE_NORMAL;
         _stateMtx.release();
      }

      OSS_INLINE UINT8 getCBState () const
      {
         return _dmsCBState ;
      }

   } ;
   typedef class _SDB_DMSCB SDB_DMSCB ;

   /*
      get global SDB_DMSCB
   */
   SDB_DMSCB* sdbGetDMSCB () ;
}

#endif //DMSCB_HPP_

