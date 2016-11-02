char* convert(char* s, int numRows) {
    char* ca = (char*)malloc((strlen(s)+1)*sizeof(char));
    int n = 0,k=0;
    int length = 0;
    if(numRows > 2 )
    {
       length = numRows*2-2;
       if(length > strlen(s))
       {
           length = strlen(s);
       }
    }
    else
    {
        length = numRows;
    }
    
    for(int i = 0 ; i < (numRows>length?length:numRows); i++)
    {
        for(int j = 0 ; j < strlen(s)/length+(strlen(s)%length>i?1:0);j++)
        {
            if( i > 0 && i<numRows-1 )
            {
                ca[k] = s[i+j*(length)]; 
                k++;
                
                if( numRows*2-2-i +j*(length) >=strlen(s))
                {
                    continue;   
                }
                
                ca[k] = s[numRows*2-2-i +j*(length)]; 
            }
            else
            {
                ca[k] = s[i+j*(length)];   
            }
            k++;
        }
    }
    
    ca[strlen(s)]='\0';
    return ca;
    
}
