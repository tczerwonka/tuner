// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_tuneL1)
// *********************************************************************
{
  // setup function
  u8g2.setFont(_LCDML_DISP_font);
  u8g2.firstPage();
  g_button_value = L1; //set to global value of L1
  do {
    // draw graphic
    //an arc with an arrow is an interesting idea but u8g2 doesn't support this
    //natively and I would rather get far enough along with the code so that
    //I can get messing with hardware instead of getting the math right -- and
    //I bet it'll be sloooooowwwww...
    //u8g2.drawCircle(64, 64, 40, U8G2_DRAW_UPPER_RIGHT|U8G2_DRAW_UPPER_LEFT);
    u8g2.drawFrame(7, 50, 102, 14);
    u8g2.drawStr(1, 61, "0"); // minimum value 
    u8g2.drawStr(110, 61, "100"); //max value
    
    u8g2.drawStr( 0, 13, "L1 position:");
    char buf[10];
    sprintf (buf, "%003d", L1);
    u8g2.drawStr(75, 13, buf);
    
    u8g2.drawStr( 0, 26, "approx uF:");
    //calculate capacitance
    char bufc[10];
    int disp_el1 = ((((L1_max - L1_min) * L1) / 100) + L1_min);
    sprintf (bufc, "%0004d", disp_el1);
    u8g2.drawStr(65, 26, bufc);

    //draw the initial bar 
    u8g2.drawBox(8, 51, L1, 13);

      
    //u8g2.drawStr( 0, 39, "any button or use");
    //u8g2.drawStr( 0, 52, "back button");
  } while ( u8g2.nextPage() );
  // Reset Button Value
  g_button_value = L1; 

}



void LCDML_DISP_loop(LCDML_FUNC_tuneL1)
{
  // loop function, can be run in a loop when LCDML_DISP_triggerMenu(xx) is set
  // the quit button works in every DISP function without any checks; it starts the loop_end function 
  
  if (LCDML_BUTTON_checkAny()) {
    if (LCDML_BUTTON_checkDown()) {
      // check if button up is pressed -- even though it says 'down'
      LCDML_BUTTON_resetDown(); // reset the down button
      if (L1 < 100) {
        //allow the user to roll past endpoints but don't do anything about it
        g_button_value++;
        L1++;
      } //if
      
      // update lcd content
      char buf[10];
      sprintf (buf, "%003d", g_button_value);
      do {
        //print the value
        u8g2.drawStr( 75, 13, buf);
        u8g2.drawBox(8, 51, g_button_value, 13);
        //calculate and print capacitance
        int disp_el1 = ((((L1_max - L1_min) * L1) / 100) + L1_min);
        char bufc[5];
        sprintf (bufc, "%0004d", disp_el1);
        u8g2.drawStr(65, 26, bufc);
      } while( u8g2.nextPage() );        
    } //if checkDown   
    
    if (LCDML_BUTTON_checkUp()) {
      LCDML_BUTTON_resetUp();
      if (L1 > 0) {
        //allow the user to roll past endpoints but don't do anything about it
        g_button_value--;
        L1--;
      } //if
      // update lcd content
      char buf[10];
      sprintf (buf, "%003d", g_button_value);
      do {
        //print the value
        u8g2.drawStr( 75, 13, buf);
        u8g2.setDrawColor(0);
        u8g2.drawBox((8+g_button_value),51,(99-g_button_value),12);
        u8g2.setDrawColor(1);
        //calculate and print capacitance
        int disp_el1 = ((((L1_max - L1_min) * L1) / 100) + L1_min);
        char bufd[5];
        sprintf (bufd, "%0004d", disp_el1);
        u8g2.drawStr(65, 26, bufd);
      } while( u8g2.nextPage() );  


    } //if checkUp

    if (LCDML_BUTTON_checkLeft()) {
      LCDML_BUTTON_resetLeft();
      LCDML_DISP_funcend();   
    } //if checkBack
  } //if checkAny
  
} //LCDML_DISP_loop



void LCDML_DISP_loop_end(LCDML_FUNC_tuneL1)
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing
}
