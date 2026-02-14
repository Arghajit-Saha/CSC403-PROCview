#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    system("ps -eLf > elf.tmp");
    system("ps aux > aux.tmp");
    system("whoami > user_info.tmp");

    char outputFile[256];
    FILE *userFile = fopen("user_info.tmp", "r");
    if(userFile) {
        char userName[128];
        if(fgets(userName, sizeof(userName), userFile)) {
            userName[strcspn(userName, "\n")] = 0;
            if(strlen(userName) > 0) 
                sprintf(outputFile, "txt_output/%s_output.txt", userName); 
            else 
                strcpy(outputFile, "txt_output/user_output.txt"); 
        } 
        else 
            strcpy(outputFile, "txt_output/user_output.txt"); 
        
        fclose(userFile);
    } 
    else 
        strcpy(outputFile, "txt_output/user_output.txt");

    FILE *elfFile = fopen("elf.tmp", "r");
    FILE *outFile = fopen(outputFile, "w");

    if(elfFile == NULL || outFile == NULL) { 
        if(elfFile) 
            fclose(elfFile); 
        if(outFile) 
            fclose(outFile); 
        return 1; 
    }
    fprintf(outFile, "UID\tPID\tPPID\tLWP\tC\tNLWP\t%%CPU\t%%MEM\tVSZ\tRSS\tTTY\tSTAT\tSTART\tTIME\tCOMMAND\n");

    char userId[50], auxId[50], parentPid[50], threadId[50], cpuUtilization[50], numElf[50];
    char lineSkipper[500];

    fgets(lineSkipper, 500, elfFile);
    while(fscanf(elfFile, "%s %s %s %s %s %s", userId, auxId, parentPid, threadId, cpuUtilization, numElf) == 6) {
        fgets(lineSkipper, 500, elfFile);
        FILE *resourcesFile = fopen("aux.tmp", "r");
        
        char resUser[50], resPid[50], resCpu[50], resMem[50], resVsz[50], resRss[50];
        char resTty[50], resStat[50], resStart[50], resTime[50], resCommand[500];

        fgets(lineSkipper, 500, resourcesFile);
        int found = 0;
        while(fscanf(resourcesFile, "%s %s %s %s %s %s %s %s %s %s %[^\n]", resUser, resPid, resCpu, resMem, resVsz, resRss, resTty, resStat, resStart, resTime, resCommand) == 11) {
            if(strcmp(auxId, resPid) == 0) {
                fprintf(outFile, "%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n", userId, auxId, parentPid, threadId, cpuUtilization, numElf, resCpu, resMem, resVsz, resRss, resTty, resStat, resStart, resTime, resCommand);
                found = 1;
                break;
            }
        }
        
        fclose(resourcesFile);
    }

    fclose(elfFile);
    fclose(outFile);

    char cat[300];
    sprintf(cat, "cat \"%s\"", outputFile);
    system(cat);
    system("rm aux.tmp elf.tmp user_info.tmp");
    return 0;
}