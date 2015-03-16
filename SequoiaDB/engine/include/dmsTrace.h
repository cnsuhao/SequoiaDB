/*    Copyright 2012 SequoiaDB Inc.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/* This list file is automatically generated,you shoud NOT modify this file anyway! test comment*/
#ifndef dmsTRACE_H__
#define dmsTRACE_H__
#define SDB__DMSSTORAGELOADEXT__ALLOCEXTENT                0x1000000000000L
#define SDB__DMSSTORAGELOADEXT__IMPRTBLOCK                 0x1000000000001L
#define SDB__DMSSTORAGELOADEXT__LDDATA                     0x1000000000002L
#define SDB__DMSSTORAGELOADEXT__ROLLEXTENT                 0x1000000000003L
#define SDB__DMS_LOBDIRECTBUF__EXTENDBUF                   0x1000000000004L
#define SDB__DMSTMPCB_INIT                                 0x1000000000005L
#define SDB__DMSTMPCB_RELEASE                              0x1000000000006L
#define SDB__DMSTMPCB_RESERVE                              0x1000000000007L
#define SDB_DMSSTORAGELOBDATA_OPEN                         0x1000000000008L
#define SDB_DMSSTORAGELOBDATA__REOPEN                      0x1000000000009L
#define SDB_DMSSTORAGELOBDATA_CLOSE                        0x100000000000aL
#define SDB_DMSSTORAGELOBDATA_WRITE                        0x100000000000bL
#define SDB_DMSSTORAGELOBDATA_READ                         0x100000000000cL
#define SDB_DMSSTORAGELOBDATA_READRAW                      0x100000000000dL
#define SDB_DMSSTORAGELOBDATA_EXTEND                       0x100000000000eL
#define SDB_DMSSTORAGELOBDATA__EXTEND                      0x100000000000fL
#define SDB_DMSSTORAGELOBDATA_REMOVE                       0x1000000000010L
#define SDB_DMSSTORAGELOBDATA__INITFILEHEADER              0x1000000000011L
#define SDB_DMSSTORAGELOBDATA__VALIDATEFILE                0x1000000000012L
#define SDB_DMSSTORAGELOBDATA__FETFILEHEADER               0x1000000000013L
#define SDB__DMSROUNIT__INIT                               0x1000000000014L
#define SDB__DMSROUNIT_CLNUP                               0x1000000000015L
#define SDB__DMSROUNIT_OPEN                                0x1000000000016L
#define SDB__DMSROUNIT_IMPMME                              0x1000000000017L
#define SDB__DMSROUNIT_EXPMME                              0x1000000000018L
#define SDB__DMSROUNIT__ALCEXT                             0x1000000000019L
#define SDB__DMSROUNIT__FLSEXT                             0x100000000001aL
#define SDB__DMSROUNIT_FLUSH                               0x100000000001bL
#define SDB__DMSROUNIT_INSRCD                              0x100000000001cL
#define SDB__DMSROUNIT_GETNXTEXTSIZE                       0x100000000001dL
#define SDB__DMSROUNIT_EXPHEAD                             0x100000000001eL
#define SDB__DMSROUNIT_EXPEXT                              0x100000000001fL
#define SDB__DMSROUNIT_VLDHDBUFF                           0x1000000000020L
#define SDB__DMSSTORAGELOB_OPEN                            0x1000000000021L
#define SDB__DMSSTORAGELOB__DELAYOPEN                      0x1000000000022L
#define SDB__DMSSTORAGELOB__OPENLOB                        0x1000000000023L
#define SDB__DMSSTORAGELOB_REMOVESTORAGEFILES              0x1000000000024L
#define SDB__DMSSTORAGELOB_GETLOBMETA                      0x1000000000025L
#define SDB__DMSSTORAGELOB_WRITELOBMETA                    0x1000000000026L
#define SDB__DMSSTORAGELOB_WRITE                           0x1000000000027L
#define SDB__DMSSTORAGELOB_UPDATE                          0x1000000000028L
#define SDB__DMSSTORAGELOB_READ                            0x1000000000029L
#define SDB__DMSSTORAGELOB__ALLOCATEPAGE                   0x100000000002aL
#define SDB__DMSSTORAGELOB__FILLPAGE                       0x100000000002bL
#define SDB__DMSSTORAGELOB_REMOVE                          0x100000000002cL
#define SDB__DMSSTORAGELOB__FIND                           0x100000000002dL
#define SDB__DMSSTORAGELOB__PUSH2BUCKET                    0x100000000002eL
#define SDB__DMSSTORAGELOB__ONCREATE                       0x100000000002fL
#define SDB__DMSSTORAGELOB__ONMAPMETA                      0x1000000000030L
#define SDB__DMSSTORAGELOB__EXTENDSEGMENTS                 0x1000000000031L
#define SDB__DMSSTORAGELOB_READPAGE                        0x1000000000032L
#define SDB__DMSSTORAGELOB__REMOVEPAGE                     0x1000000000033L
#define SDB__DMSSTORAGELOB_TRUNCATE                        0x1000000000034L
#define SDB__DMSSMS__RSTMAX                                0x1000000000035L
#define SDB__DMSSMS_RSVPAGES                               0x1000000000036L
#define SDB__DMSSMS_RLSPAGES                               0x1000000000037L
#define SDB__DMSSMEMGR_INIT                                0x1000000000038L
#define SDB__DMSSMEMGR_RSVPAGES                            0x1000000000039L
#define SDB__DMSSMEMGR_RLSPAGES                            0x100000000003aL
#define SDB__DMSSMEMGR_DEPOSIT                             0x100000000003bL
#define SDB__SDB_DMSCB__LGCSCBNMMAP                        0x100000000003cL
#define SDB__SDB_DMSCB__CSCBNMINST                         0x100000000003dL
#define SDB__SDB_DMSCB__CSCBNMREMV                         0x100000000003eL
#define SDB__SDB_DMSCB__CSCBNMREMVP1                       0x100000000003fL
#define SDB__SDB_DMSCB__CSCBNMREMVP1CANCEL                 0x1000000000040L
#define SDB__SDB_DMSCB__CSCBNMREMVP2                       0x1000000000041L
#define SDB__SDB_DMSCB__CSCBNMMAPCLN                       0x1000000000042L
#define SDB__SDB_DMSCB_ADDCS                               0x1000000000043L
#define SDB__SDB_DMSCB_DELCS                               0x1000000000044L
#define SDB__SDB_DMSCB_DROPCSP1                            0x1000000000045L
#define SDB__SDB_DMSCB_DROPCSP1CANCEL                      0x1000000000046L
#define SDB__SDB_DMSCB_DROPCSP2                            0x1000000000047L
#define SDB__SDB_DMSCB_DUMPINFO                            0x1000000000048L
#define SDB__SDB_DMSCB_DUMPINFO2                           0x1000000000049L
#define SDB__SDB_DMSCB_DUMPINFO3                           0x100000000004aL
#define SDB__SDB_DMSCB_DUMPINFO4                           0x100000000004bL
#define SDB__SDB_DMSCB_DISPATCHPAGECLEANSU                 0x100000000004cL
#define SDB__SDB_DMSCB_JOINPAGECLEANSU                     0x100000000004dL
#define SDB__SDB_DMSCB__JOINPAGECLEANSU                    0x100000000004eL
#define SDB__DMS_LOBDIRECTOUTBUF_GETALIGNEDTUPLE           0x100000000004fL
#define SDB_DMSCHKCSNM                                     0x1000000000050L
#define SDB_DMSCHKFULLCLNM                                 0x1000000000051L
#define SDB_DMSCHKCLNM                                     0x1000000000052L
#define SDB_DMSCHKINXNM                                    0x1000000000053L
#define SDB__DMS_LOBDIRECTINBUF_GETALIGNEDTUPLE            0x1000000000054L
#define SDB__DMS_LOBDIRECTINBUF_CP2USRBUF                  0x1000000000055L
#define SDB__MBFLAG2STRING                                 0x1000000000056L
#define SDB__MBATTR2STRING                                 0x1000000000057L
#define SDB__DMSMBCONTEXT                                  0x1000000000058L
#define SDB__DMSMBCONTEXT_DESC                             0x1000000000059L
#define SDB__DMSMBCONTEXT__RESET                           0x100000000005aL
#define SDB__DMSMBCONTEXT_PAUSE                            0x100000000005bL
#define SDB__DMSMBCONTEXT_RESUME                           0x100000000005cL
#define SDB__DMSSTORAGEDATA                                0x100000000005dL
#define SDB__DMSSTORAGEDATA_DESC                           0x100000000005eL
#define SDB__DMSSTORAGEDATA_SYNCMEMTOMMAP                  0x100000000005fL
#define SDB__DMSSTORAGEDATA__ONCREATE                      0x1000000000060L
#define SDB__DMSSTORAGEDATA__ONMAPMETA                     0x1000000000061L
#define SDB__DMSSTORAGEDATA__ONCLOSED                      0x1000000000062L
#define SDB__DMSSTORAGEDATA__INITMME                       0x1000000000063L
#define SDB__DMSSTORAGEDATA__LOGDPS                        0x1000000000064L
#define SDB__DMSSTORAGEDATA__LOGDPS1                       0x1000000000065L
#define SDB__DMSSTORAGEDATA__ALLOCATEEXTENT                0x1000000000066L
#define SDB__DMSSTORAGEDATA__FREEEXTENT                    0x1000000000067L
#define SDB__DMSSTORAGEDATA__RESERVEFROMDELETELIST         0x1000000000068L
#define SDB__DMSSTORAGEDATA__TRUNCATECOLLECTION            0x1000000000069L
#define SDB__DMSSTORAGEDATA__TRUNCATECOLLECITONLOADS       0x100000000006aL
#define SDB__DMSSTORAGEDATA__SAVEDELETEDRECORD             0x100000000006bL
#define SDB__DMSSTORAGEDATA__SAVEDELETEDRECORD1            0x100000000006cL
#define SDB__DMSSTORAGEDATA__MAPEXTENT2DELLIST             0x100000000006dL
#define SDB__DMSSTORAGEDATA_ADDEXTENT2META                 0x100000000006eL
#define SDB__DMSSTORAGEDATA_ADDCOLLECTION                  0x100000000006fL
#define SDB__DMSSTORAGEDATA_DROPCOLLECTION                 0x1000000000070L
#define SDB__DMSSTORAGEDATA_TRUNCATECOLLECTION             0x1000000000071L
#define SDB__DMSSTORAGEDATA_TRUNCATECOLLECTIONLOADS        0x1000000000072L
#define SDB__DMSSTORAGEDATA_RENAMECOLLECTION               0x1000000000073L
#define SDB__DMSSTORAGEDATA_FINDCOLLECTION                 0x1000000000074L
#define SDB__DMSSTORAGEDATA_INSERTRECORD                   0x1000000000075L
#define SDB__DMSSTORAGEDATA__EXTENTINSERTRECORD            0x1000000000076L
#define SDB__DMSSTORAGEDATA_DELETERECORD                   0x1000000000077L
#define SDB__DMSSTORAGEDATA__EXTENTREMOVERECORD            0x1000000000078L
#define SDB__DMSSTORAGEDATA_UPDATERECORD                   0x1000000000079L
#define SDB__DMSSTORAGEDATA__EXTENTUPDATERECORD            0x100000000007aL
#define SDB__DMSSTORAGEDATA_FETCH                          0x100000000007bL
#define SDB__DMSSU                                         0x100000000007cL
#define SDB__DMSSU_DESC                                    0x100000000007dL
#define SDB__DMSSU_OPEN                                    0x100000000007eL
#define SDB__DMSSU_CLOSE                                   0x100000000007fL
#define SDB__DMSSU_REMOVE                                  0x1000000000080L
#define SDB__DMSSU__RESETCOLLECTION                        0x1000000000081L
#define SDB__DMSSU_LDEXTA                                  0x1000000000082L
#define SDB__DMSSU_LDEXT                                   0x1000000000083L
#define SDB__DMSSU_INSERTRECORD                            0x1000000000084L
#define SDB__DMSSU_UPDATERECORDS                           0x1000000000085L
#define SDB__DMSSU_DELETERECORDS                           0x1000000000086L
#define SDB__DMSSU_REBUILDINDEXES                          0x1000000000087L
#define SDB__DMSSU_CREATEINDEX                             0x1000000000088L
#define SDB__DMSSU_DROPINDEX                               0x1000000000089L
#define SDB__DMSSU_DROPINDEX1                              0x100000000008aL
#define SDB__DMSSU_COUNTCOLLECTION                         0x100000000008bL
#define SDB__DMSSU_GETCOLLECTIONFLAG                       0x100000000008cL
#define SDB__DMSSU_CHANGECOLLECTIONFLAG                    0x100000000008dL
#define SDB__DMSSU_GETCOLLECTIONATTRIBUTES                 0x100000000008eL
#define SDB__DMSSU_UPDATECOLLECTIONATTRIBUTES              0x100000000008fL
#define SDB__DMSSU_GETSEGEXTENTS                           0x1000000000090L
#define SDB__DMSSU_GETINDEXES                              0x1000000000091L
#define SDB__DMSSU_GETINDEX                                0x1000000000092L
#define SDB__DMSSU_DUMPINFO                                0x1000000000093L
#define SDB__DMSSU_DUMPINFO1                               0x1000000000094L
#define SDB__DMSSU_DUMPINFO2                               0x1000000000095L
#define SDB__DMSSU_TOTALSIZE                               0x1000000000096L
#define SDB__DMSSU_TOTALDATAPAGES                          0x1000000000097L
#define SDB__DMSSU_TOTALDATASIZE                           0x1000000000098L
#define SDB__DMSSU_TOTALFREEPAGES                          0x1000000000099L
#define SDB__DMSSU_GETSTATINFO                             0x100000000009aL
#endif
