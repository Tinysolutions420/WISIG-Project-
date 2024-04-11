/** Author Keval Malde */

#ifndef __PHY_READ_STATS_H__
#define __PHY_READ_STATS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_SLOT_IDX 1024
#define MAX_SLOT 20

typedef enum direction
{
    DL = 0,
    UL
} directionE;

typedef enum shared
{
    DS = 0,
    US 
} sharedE;

/** Enum to determine if the data is PDCCH or DCI */
typedef enum pdcchType
{
    PDCCH = 0,
    DCI = 1
} pdcchTypeE;

/** Enum to determin PUCCH format type */
typedef enum pucchFormat
{
    PUCCH_FORMAT_0 = 0,
    PUCCH_FORMAT_1,
    PUCCH_FORMAT_2,
    PUCCH_FORMAT_3,
    PUCCH_FORMAT_4
} pucchFormatE;

/** Enum to determin PUCCH flag type */
typedef enum pucchFlags
{
    DMRS_FLAG = 0,
    SRS_FLAG,
    FREQ_HOP_FLAG,
    SEQ_HOP_FLAG,
    GROUP_HOP_FLAG
} pucchFlagsE;

/** Structure to store pucch info */
typedef struct pucch
{
    pucchFormatE format;    /** PUCCH format */
    pucchFlagsE flag;       /** Determine PUCCH message type */
    int startPrb;           /** Start PRB */
    int nRb;                /** Number of RBs */
    int startSym;           /** Start symbol */
    int SymNum;             /** Symbol number */
    int startPrb2NdHop;     /** Start of the 2nd hop PRB */
    int payloadLen;         /** Payload length */
    int ta;                 /** Timing advance */
    int taAvgEst;           /** Average TA */
    int snr;                /** SNR */
    int avgSnr;             /** Average SNR */
} pucchT,
 *pucchP;

/** Structure to store pusch info */
typedef struct pusch
{
    int harqId;     /** Harq ID */
    int rbStart;    /** RB start */
    int nRb;        /** Number of RBs */
    int nSymbStart; /** Symbol Start */
    int nSymb;      /** Number of Symbol */
    int nCodeWord;  /** N codeword */
    int nLayers;    /** Number of layers */
} puschT,
 *puschP;

/** Structure to store prach info */
typedef struct prach
{
    int configIdx;  /** Prach config index */
    int detect;     /** Prach dected or not */
    int ta;         /** Timing advance */
    int nPwr;       /** Preamble power */
} prachT,
 *prachP;

/** SSB info */
typedef struct ssb
{
    int ssbPeriod;  /** SSB period */
    int nRbStart;   /** RB start  */
    int nReOffset;  /** RE Offset */
    int nSybStart;  /** Symbol Start */
} ssbT,
 *ssbP;

/** Struct to store pdcch data */
typedef struct pdcchDci
{
    pdcchTypeE type; /** 0 for PDCCH, 1 for DCI */
    int rbStart;     /** Start of RB */
    int noRbs;       /** Number of RBs */
    int symbStart;   /** Start of Symbols */
    int noOfSymb;    /** Number of Symbols */
    int startRb;     /** Start RB */
    int endRb;       /** End RB */
} pdcchDciT,
 *pdcchDciP;

/** Structure to store PDSCH data */
typedef struct pdsch
{
    int harqId;     /** Harq ID */
    int rbStart;    /** RB start */
    int nRb;        /** Number of RBs */
    int nSymbStart; /** Symbol Start */
    int nSymb;      /** Number of Symbol */
    int nCodeWord;  /** N codeword */
    int nLayers;    /** Number of layers */
} pdschT,
 *pdschP;

/** To store throughput info */
typedef struct tptuInfo
{
    int noOfTb;                 /** To store Number of TBs persent */
    int codewordId[2];          /** To store code word ID */
    int sharedChannelRB[2];     /** To store channel RB info, if DL PDSCH else PUSCH*/
    int sharedChannelBit[2];    /** To store bits for TTI if DL PDSCH else PUSCH */
} tptuInfoT,
 *tptuInfoP;

/** Structure to store channel info */
typedef struct channelInfo
{
    int noOfChannel;    /** To store how many channels are presnet in this slot */
    int channel0;       /** If Dir is DL then indicate SSB is present else indicate PRACH is present */
    int channel1;       /** If Dir is DL then indicate PDSCH is present else indicate PUSCH is present */
    int channel2;       /** If Dir is DL then indicate PDCCH is present else indicate PUCCH is present */
    int channel3;       /** If Dir is DL then indicate DL control symb is present else indicate SRS is present */
} channelInfoT,
 *channelInfoP;

/** Slot info for each slot regardless of DL or UL */
typedef struct Slot
{
    int slot[MAX_SLOT];   /** TO store count of which slot is presnet*/
} SlotT,
 *SlotP;

/** To store DL slot counters */
typedef struct dlSlotInfo
{
    SlotT ssbSlot;          /** SSB slot occurance and count*/
    SlotT pdschSlot;        /** PDSCH slot occurance and count*/
    SlotT pdcchSlot;        /** PDCCH slot occurance and count*/
} dlSlotInfoT,
 *dlSlotInfoP;

/** To store UL slot counters */
typedef struct ulSlotInfo
{
    SlotT prachSlot;        /** Prach slot occurance and count*/
    SlotT puschSlot;        /** Pusch slot occurance and count*/
    SlotT pucchSlot;        /** Pucch slot occurance and count*/
} ulSlotInfoT,
 *ulSlotInfoP;

/** Get slot info */
typedef struct getSlotStats
{
    ulSlotInfoT ulSlot;     /** Slots Stats for all UL slot */
    dlSlotInfoT dlSlot;     /** Slots Stats for all DL slot */
} getSlotStatsT,
 *getSlotStatsP;


/** Structure to store slot information */
typedef struct slotInfo
{
    int subFrameNo[2][1024];              /** Storing the subframe info */
    int slotNo[2][1024]; 
    int symbNo[2][1024]; 
    int rb_data[2][1024];  
     int rb_start[2][1024];               /** Storing the slot info */
    directionE dir[2][1024];             /** To store direction 0 for DL and 1 for UL */
    sharedE shar[2][1024];
    channelInfoT channelInfo[2][1024];    /** To store channel related info */
    tptuInfoT tptInfo[2][1024];           /** Throughput info */
    getSlotStatsP slotStat;
    pdschT pdsch[2][1024];
    puschT pusch[2][1024];
} slotInfoT,
 *slotInfoP;


FILE* getFilePtr ();
slotInfoP initSlot();
void getSlotInfo ( FILE *fp, slotInfoP slot );
getSlotStatsP initSlotStats ( slotInfoP slot);
void dealloc ( FILE *fp, slotInfoP slot );
void createCsv ( slotInfoP slot );

#endif /** __PHY_READ_STATS_H__ */
