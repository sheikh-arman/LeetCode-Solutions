///Copied
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int remainingBytes = 0;
        for(auto iter:data){
            if(remainingBytes==0){ // remaining bytes = 0 means now we are at a byte which will
                // tell the length of the sequence it is included in
                    if(iter >> 7 == 0b0){ // this means 1 byte including itself
                        remainingBytes = 0;
                    }
                    else if(iter >> 5 == 0b110){// this means 2 byte including itself
                        remainingBytes = 1;
                    }
                    else if(iter >> 4 == 0b1110){// this means 3 byte including itself
                        remainingBytes = 2;
                    }
                    else if(iter >> 3 == 0b11110){// this means 4 byte including itself
                        remainingBytes = 3; //three numbers ahead this to be checked if start with 01
                    }
                    else return false;
            }
            else{
                if(iter >> 6 != 0b10) return false; // if bytes other than 1st byte of n-byte sequence start with 0 or not
                remainingBytes--;
            }
        }
        return remainingBytes == 0;
    }
};