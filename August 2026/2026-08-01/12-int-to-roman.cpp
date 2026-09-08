// 12 leetcode int-to-roman;math_string;help

char* intToRoman(int num) {
    char *result = (char*)malloc(20 * sizeof(char)); 
    result[0] = '\0';
    char *thousand[] = {"", "M", "MM", "MMM"};
    char *hundred[]  = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char *ten[]      = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char *one[]      = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    
    strcat(result, thousand[num / 1000]);         
    strcat(result, hundred[(num % 1000) / 100]);  
    strcat(result, ten[(num % 100) / 10]);        
    strcat(result, one[num % 10]);                

    return result;
}