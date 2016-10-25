int lengthOfLongestSubstring(char* s) {
    int max = 0;
    int curLong = 0;
    int curPos = 0;
    int prevPos = 0;
    char* lastPos = 0;
    char caSubstr[1024] = {0};
    
    while(s[curPos] != '\0')
    {
        memset(caSubstr,0,sizeof(caSubstr));
        curLong = curPos-prevPos+1;   
        if(curLong > max )
        {
            max = curLong;
        }
        
        curPos++;
        
        memcpy(caSubstr,s+prevPos,curLong);
        
        lastPos = strchr(caSubstr,s[curPos]);

        if(lastPos != 0)
        {
            prevPos = curPos-strlen(lastPos)+1;
        }
 

    }
    return max;
    
    
}
