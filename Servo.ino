int pos = 90;
void readKeyboard(){
    if(Serial.available() > 0){
       int readChar = Serial.read();
       Serial.println(readChar);
       if(readChar == 'a'){
         for(int i = pos; i > 45; i -= 1)  
          {          
            pos = i;             
            myservo.write(i);            
            delay(15);                      
          } 
       }
       else if(readChar == 'b'){
          if(pos <90){
            for(int i = pos; i < 90; i += 1)
            {   
              pos = i;             
              myservo.write(i);               
              delay(15);                        
            } 
          }
          else{
            for(int i = pos; i > 90; i -= 1)
            {   
              pos = i;             
              myservo.write(i);               
              delay(15);                        
            } 
          }
       }
       else if( readChar == 'c'){      
          for(int i = pos; i < 135; i += 1)  
          {         
            pos = i;            
            myservo.write(i);              
            delay(15);                      
          } 
       }
    } 
}
