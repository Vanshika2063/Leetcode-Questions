class Solution {
    
    public String ones(int num)
    {
        switch(num)
        {
            case 1 : return "One ";
            case 2 : return "Two ";
            case 3 : return "Three ";
            case 4 : return "Four ";
            case 5 : return "Five ";
            case 6 : return "Six ";
            case 7 : return "Seven ";
            case 8 : return "Eight ";
            case 9 : return "Nine ";
            case 10 : return "Ten ";    
        }
        
        return "";
    }
    
    public String tens(int num)
    {
        switch(num)
        {
            
            case 20  : return "Twenty ";
            case 30 : return "Thirty ";
            case 40 : return "Forty ";
            case 50 : return "Fifty ";
            case 60 : return "Sixty ";
            case 70 : return "Seventy ";
            case 80 : return "Eighty ";
            case 90 : return "Ninety ";
                
        }
        return "";
    }
    
    public String less_20(int num)
    {
        switch(num)
        {
            case 11 : return "Eleven ";
            case 12 : return "Twelve ";
            case 13 : return "Thirteen ";
            case 14 : return "Fourteen ";
            case 15 : return "Fifteen ";
            case 16 : return "Sixteen ";
            case 17 : return "Seventeen ";
            case 18 : return "Eighteen ";
            case 19 : return "Nineteen ";            
        }
        return "";
        
    }

    public String three(int num)
    {
        int hundreds = num / 100;
        
        int rest = num % 100;
        String res="";
        if(hundreds != 0)
            res += ones(hundreds) + "Hundred ";
        
        
        if(rest  >= 20)
        {
            int ties = (rest/10) * 10;
            int one = rest % 10;
            
            res += tens(ties) + ones(one);
            
        }
        
        else
        {
            if(rest <= 10)
            res += ones(rest);
            
            else
                res+= less_20(rest); 
        }
        
        return res;
        
    }
    
    
    public String numberToWords(int num) {
        if(num == 0)
            return "Zero";
        
        String res = "";
        
            
        int billions = num / 1000000000;
        int millions = (num - (billions *  1000000000)) / 1000000;
        int thousands = (num - (billions *  1000000000) - (millions * 1000000)) / 1000;
        int rest = (num - (billions *  1000000000) - (millions * 1000000) - (thousands * 1000));
        
        
        if(billions != 0)
        {
        res+= three(billions) + "Billion ";
         
        }
        
        if(millions != 0)
        {
        res+=three(millions) + "Million ";    
            
        }
        
        if(thousands !=0 )
        {
            res+=three(thousands) + "Thousand ";    
        }
        
        if(rest != 0)
        res += three(rest);
       
        return res.substring(0, res.length()-1);
    }
}
