#include "PhyReadStats.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * @brief Funtion to open file and store the file pointer
 * 
 * @returns Valid file pointer if fopen is success else NULL pointer in case of failure
 */
FILE* getFilePtr ()
{
    FILE *phyStatsFile = NULL;

    phyStatsFile = fopen ( "PhyStats-c0_wls.txt", "r" );

    return phyStatsFile;
}


/**
 * @brief Function to allocate memory for slot info structure (Super Structure)
 * 
 * @returns Valid pointer if memory allocation was successfull else NULL pointer
 */
//** To allocate memory for slot */
slotInfoP initSlot()
{
    slotInfoP slot = ( slotInfoP ) calloc ( 1, sizeof ( slotInfoT ));
    if ( NULL == slot )
    {
        printf("Failed to allocate memory\n");
    }
    return slot;
}


/**
 * @brief Funtion to store basic info such as snf, slot , dir, channel related info
 * 
 * @param fp: Pointer to Phy Stats file
 * @param slot: Pointer to slot stricture
 * @returns void
 */
void getSlotInfo ( FILE *fp, slotInfoP slot )
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int lineDlNum = 0;                  /** To keep track of how many lines we have stored so far in DL */
    int lineUlNum = 0;                  /** To keep track of how many lines we have stored so far in UL */
    int lineDlNum1 = 0; 
    int lineUlNum1 = 0; 
    while ( ( read = getline (&line, &len, fp) ) != -1 ) // getline extract each line in the file and store in len
    {

        for ( int i=0; i<len; i++ )
        {
            /** Since DL can be present anywhere if first char is ( then only we are intrested in encoutiring */
            if ( (line[i] == 'D' && line[i+1] == 'L' && line[0] == '(' )) 
            {

                slot->dir[DL][lineDlNum] = DL;
                int k = 2;          /** This hardcoding is done as we know that char 0 will be starting char */
                int frameLen = 0;   /** To count the frame length it can be 2,3,4 char long as it represent sfn */
                while ( 1 )
                {
                    frameLen++;
                    k++;
                    if ( line[k] == ',' ) break;
                }

                /** Getting slot info */
                if ( line[k+3] == '1' )
                {
                    char slotInf[2] = {};
                    slotInf[0] = line[k+3];
                    slotInf[1] = line[k+4];
                    slot->slotNo[DL][lineDlNum] = atoi(slotInf);
                }
                else
                {
                    char slotInf[1] = {};
                    slot->slotNo[DL][lineDlNum] = atoi(&line[k+4]);
                }

                k=2;    // If this changes then offset for copy needs to be adjusted 
                char *frame = ( char * ) calloc (frameLen, sizeof(char));
                if ( NULL == frame )
                {
                    printf("critical error\n");
                    return;
                }
                while ( 1 )
                {
                    frame[k-2] = line[k];           /** Copy SFN */
                    k++;
                    if ( line[k] == ',' ) break;
                }
                slot->subFrameNo[DL][lineDlNum] = atoi(frame);     /** Convert it to int */
                //printf("%d %d %d %d\n", slot->subFrameNo[lineDlNum], slot->slotNo[lineDlNum], slot->dir[lineDlNum], lineDlNum);

                /** Getting channel info */
                slot->channelInfo[DL][lineDlNum].channel0 = atoi(&line[i+8]);
                slot->channelInfo[DL][lineDlNum].channel1 = atoi(&line[i+11]);
                slot->channelInfo[DL][lineDlNum].channel2 = atoi(&line[i+15]);
                slot->channelInfo[DL][lineDlNum].channel3 = atoi(&line[i+18]);
                slot->channelInfo[DL][lineDlNum].noOfChannel = slot->channelInfo[DL][lineDlNum].channel0 +
                                                           slot->channelInfo[DL][lineDlNum].channel1 +
                                                           slot->channelInfo[DL][lineDlNum].channel2 +
                                                           slot->channelInfo[DL][lineDlNum].channel3;

                //printf("frame:%d,slot:%d\n", slot->subFrameNo[DL][lineDlNum],slot->slotNo[DL][lineDlNum] );
                // pdsch DATA 
                free (frame);
                lineDlNum++;
                //printf("check_1=%d\n",lineDlNum);
                //printf("frame:%d\n", slot->subFrameNo[DL][lineDlNum] );

            }

            
    



            else if ( (line[i] == 'U' && line[i+1] == 'L' && line[0] == '(' )) 
            {
                slot->dir[UL][lineUlNum] = UL;
                int k = 2;          /** This hardcoding is done as we know that char 0 will be starting char */
                int frameLen = 0;   /** To count the frame length it can be 2,3,4 char long as it represent sfn */
                while ( 1 )
                {
                    frameLen++;
                    k++;
                    if ( line[k] == ',' ) break;
                }

                /** Getting slot info */
                if ( line[k+3] == '1' )
                {
                    char slotInf[2] = {};
                    slotInf[0] = line[k+3];
                    slotInf[1] = line[k+4];
                    slot->slotNo[UL][lineUlNum] = atoi(slotInf);
                }
                else
                {
                    char slotInf[1] = {};
                    slot->slotNo[UL][lineUlNum] = atoi(&line[k+4]);
                }

                k=2;    // If this changes then offset for copy needs to be adjusted 
                char *frame = ( char * ) calloc (frameLen, sizeof(char));
                if ( NULL == frame )
                {
                    printf("critical error\n");
                    return;
                }
                while ( 1 )
                {
                    frame[k-2] = line[k];           /** Copy SFN */
              
                    k++;
                    if ( line[k] == ',' ) break;
                }
                slot->subFrameNo[UL][lineUlNum] = atoi(frame);     /** Convert it to int */
           
                /** Getting channel info */
                slot->channelInfo[UL][lineUlNum].channel0 = atoi(&line[i+8]);
                slot->channelInfo[UL][lineUlNum].channel1 = atoi(&line[i+11]);
                slot->channelInfo[UL][lineUlNum].channel2 = atoi(&line[i+15]);
                slot->channelInfo[UL][lineUlNum].channel3 = atoi(&line[i+18]);
                slot->channelInfo[UL][lineUlNum].noOfChannel = slot->channelInfo[UL][lineUlNum].channel0 +
                                                           slot->channelInfo[UL][lineUlNum].channel1 +
                                                           slot->channelInfo[UL][lineUlNum].channel2 +
                                                           slot->channelInfo[UL][lineUlNum].channel3;  

               
                free (frame);   
                lineUlNum++;      
            }
           
        }
    }
}




/**
 * @brief Function to get channel info such as which logical channel came in which slot and its frequency
 *
 * @param slot: Pointer to slot structure
 * 
 */


void getChannelInfo ( slotInfoP slot )
{
    for ( int i=0; i < MAX_SLOT_IDX; i++ )
    {
        
        if ( slot->dir[DL][i] == DL)
        {
            int snf = slot->subFrameNo[DL][i];
            int slotNum = slot->slotNo[DL][i];
            int ssb = slot->channelInfo[DL][i].channel0;
            if ( ssb > 0 )
            {
                /** Increament the counter if channel is present in this slot */
                slot->slotStat->dlSlot.ssbSlot.slot[slotNum]++;
            }
            int pdsch = slot->channelInfo[DL][i].channel1;
            if ( pdsch > 0 )
            {
                /** Increament the counter if channel is present in this slot */
                slot->slotStat->dlSlot.pdschSlot.slot[slotNum]++;
            }
            int pdcch = slot->channelInfo[DL][i].channel2;
            if ( pdcch > 0 )
            {
                /** Increament the counter if channel is present in this slot */
                slot->slotStat->dlSlot.pdcchSlot.slot[slotNum]++;
            }
            //int Num_Rb = slot->rb_data[DS][i];
           // slot->rb_data[DS][lineDlNum1] = atoi(rb);
           
            
            printf("Sfn: %4d, Slot: %2d, SSB: %3d, PDSCH: %d, PDCCH %d\n", snf, slotNum, ssb, pdsch,pdcch);
        }
        

        if ( UL == slot->dir[UL][i] )
        {
            int snf = slot->subFrameNo[UL][i];
            int slotNum = slot->slotNo[UL][i];
            int prach = slot->channelInfo[UL][i].channel0;
            if ( prach > 0)
            {
                /** Increament the counter if channel is present in this slot */
                slot->slotStat->ulSlot.prachSlot.slot[slotNum]++;
            }
            int pusch = slot->channelInfo[UL][i].channel1;
            if ( pusch > 0)
            {
                /** Increament the counter if channel is present in this slot */
                slot->slotStat->ulSlot.puschSlot.slot[slotNum]++;
            }
            int pucch = slot->channelInfo[UL][i].channel2;
            if ( pucch > 0)
            {
                /** Increament the counter if channel is present in this slot */
                slot->slotStat->ulSlot.pucchSlot.slot[slotNum]++;
            }
            //int Num_Rb = slot->rb_data[US][i];
            //int us_harq = slot->pusch[US][i].harqId;
            

            printf("Sfn: %4d, Slot: %2d, PRACH: %d, PUSCH: %d,PUCCH %d\n", snf, slotNum, prach, pusch,pucch);
        }
        
       
   }
}


/**
 * @brief Function to show Slot stats such as which channel was mapped to which slot
 * 
 * @param slot: Pointer to slot structure
 */
void getSlotStats ( slotInfoP slot )
{
    int slotCnt = 0;
    printf("SSB is present in following slot:");
    for ( int i=0; i < MAX_SLOT; i++ )
    {
        if ( slot->slotStat->dlSlot.ssbSlot.slot[i] > 0 )
        {
            printf("%d ", i);
            slotCnt++;
        }
    }
    printf("\nTotal SSB observed is %d\n", slotCnt);

    slotCnt = 0;
    printf("PDSCH is present in following slot:");
    for ( int i=0; i < MAX_SLOT; i++ )
    {
        if ( slot->slotStat->dlSlot.pdschSlot.slot[i] > 0 )
        {
            printf("%d ", i);
            slotCnt++;
        }
    }
    printf("\nTotal PDSCH observed is %d\n", slotCnt);

    slotCnt = 0;
    printf("PDCCH is present in following slot:");
    for ( int i=0; i < MAX_SLOT; i++ )
    {
        if ( slot->slotStat->dlSlot.pdcchSlot.slot[i] > 0 )
        {
            printf("%d ", i);
            slotCnt++;
        }
    }
    printf("\nTotal PDCCH observed is %d\n", slotCnt);

    slotCnt = 0;
    printf("PRACH is present in following slot:");
    for ( int i=0; i < MAX_SLOT; i++ )
    {
        if ( slot->slotStat->ulSlot.prachSlot.slot[i] > 0 )
        {
            printf("%d ", i);
            slotCnt++;
        }
    }
    printf("\nTotal PRACH observed is %d\n", slotCnt);

    slotCnt = 0;
    printf("PUSCH is present in following slot:");
    for ( int i=0; i < MAX_SLOT; i++ )
    {
        if ( slot->slotStat->ulSlot.puschSlot.slot[i] > 0 )
        {
            printf("%d ", i);
            slotCnt++;
        }
    }
    printf("\nTotal PUSCH observed is %d\n", slotCnt);

    slotCnt = 0;
    printf("PUCCH is present in following slot:");
    for ( int i=0; i < MAX_SLOT; i++ )
    {
        if ( slot->slotStat->ulSlot.pucchSlot.slot[i] > 0 )
        {
            printf("%d ", i);
            slotCnt++;
        }
    }
    printf("\nTotal PUCCH observed is %d\n", slotCnt);

}


/**
 * @brief Function to allocate memory for slot structure
 * 
 * @param slot: Pointer to slot structure
 * @returns In case of success it returns memory for desired struct else it returne NULL pointer
 */
getSlotStatsP initSlotStats ( slotInfoP slot)
{
    slot->slotStat = ( getSlotStatsP ) calloc( 1, sizeof ( getSlotStatsT ) );
    if ( NULL == slot->slotStat )
    {
        printf("Fail to allocate memory\n");
    }
    return slot->slotStat;
}

/**
 * @brief Function to close all open files and to derefernce all memory
 */
void dealloc ( FILE *fp, slotInfoP slot )
{
    fclose(fp);
    free (slot->slotStat);
    free (slot);
}


/**
 * @brief Function to create CSV file for time and other info
 * 
 * @param slot: Pointer to slot function
 * @return 
 */
void createCsv ( slotInfoP slot )
{
    FILE *timeSeriesInfoDl = NULL;
    FILE *timeSerierInfoUL = NULL;
    int startIdx = 0;

    timeSeriesInfoDl = fopen("PhyStatsInfoDL.csv", "w+");
    if ( NULL == timeSeriesInfoDl )
    {
        printf("Failed to allocate memory\n");
        return;
    }

    fprintf(timeSeriesInfoDl, "sfn,slot,ssb,pdsch,pdcch\n");
    for ( int i=0; i<MAX_SLOT_IDX;i++)
    {
        fprintf(timeSeriesInfoDl, "%d,%2d,%d,%d,%d\n", 
                                 slot->subFrameNo[DL][i],
                                 slot->slotNo[DL][i],
                                 slot->channelInfo[DL][i].channel0,
                                 slot->channelInfo[DL][i].channel1,
                                 slot->channelInfo[DL][i].channel2);
    }

    fclose(timeSeriesInfoDl);


    timeSerierInfoUL = fopen("PhyStatsInfoUL.csv", "w+");
    if ( NULL == timeSerierInfoUL )
    {
        printf("Failed to allocate memory\n");
        return;
    }

    fprintf(timeSerierInfoUL, "sfn,slot,ssb,pdsch,pdcch\n");
    for ( int i=0; i<MAX_SLOT_IDX;i++)
    {
        fprintf(timeSerierInfoUL, "%d,%2d,%d,%d,%d\n", 
                                 slot->subFrameNo[DL][i],
                                 slot->slotNo[DL][i],
                                 slot->channelInfo[DL][i].channel0,
                                 slot->channelInfo[DL][i].channel1,
                                 slot->channelInfo[DL][i].channel2);
    }

    fclose(timeSerierInfoUL);}

/**
 * @brief Main structure (entry point)
 */
int main ()
{
    /* directionE dir = UL ;
    printf("%d\n",dir); */
    FILE *phyStatsFile = NULL;
    slotInfoP slot = NULL;

    phyStatsFile = getFilePtr();

    if ( NULL == phyStatsFile )
    {
        return -1;
    }
    
    slot = initSlot();
    if ( NULL == initSlot() )
    {
        return -1;
    }

    getSlotInfo (phyStatsFile, slot);
    // printf("finalcheck=%d\n", slot->rb_data[1][0]);
     // printf("finalcheck=%d\n", slot->rb_data[1][1]);

    if ( NULL == initSlotStats (slot) )
    {
        return -1;
    }
   

    getChannelInfo (slot);

    getSlotStats ( slot );

    createCsv (slot);

    dealloc ( phyStatsFile, slot );

    return 0;
}
