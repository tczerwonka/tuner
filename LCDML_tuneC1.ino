/* ===================================================================== *
 *                                                                       *
   DISPLAY SYSTEM
 *                                                                       *
   =====================================================================
   every "disp menu function" needs three functions
   - void LCDML_DISP_setup(func_name)
   - void LCDML_DISP_loop(func_name)
   - void LCDML_DISP_loop_end(func_name)

   EXAMPLE CODE:
    void LCDML_DISP_setup(..menu_func_name..)
    {
      // setup
      // is called only if it is started

      // starts a trigger event for the loop function every 100 millisecounds
      LCDML_DISP_triggerMenu(100);
    }

    void LCDML_DISP_loop(..menu_func_name..)
    {
      // loop
      // is called when it is triggert
      // - with LCDML_DISP_triggerMenu( millisecounds )
      // - with every button status change

      // check if any button is presed (enter, up, down, left, right)
      if(LCDML_BUTTON_checkAny()) {
        LCDML_DISP_funcend();
      }
    }

    void LCDML_DISP_loop_end(..menu_func_name..)
    {
      // loop end
      // this functions is ever called when a DISP function is quit
      // you can here reset some global vars or do nothing
    }
   =====================================================================
*/

// *********************************************************************
void LCDML_DISP_setup(LCDML_FUNC_tuneC1)
// *********************************************************************
{
  // setup function
  u8g2.setFont(_LCDML_DISP_font);
  u8g2.firstPage();
  g_button_value = C1; //set to global value of C1
  do {
    // draw graphic
    //an arc with an arrow is an interesting idea but u8g2 doesn't support this
    //natively and I would rather get far enough along with the code so that
    //I can get messing with hardware instead of getting the math right -- and
    //I bet it'll be sloooooowwwww...
    //u8g2.drawCircle(64, 64, 40, U8G2_DRAW_UPPER_RIGHT|U8G2_DRAW_UPPER_LEFT);
    u8g2.drawFrame(9, 50, 100, 13);
    u8g2.drawStr(1, 61, "0"); // minimum value
    u8g2.drawStr(110, 61, "100"); //max value
    u8g2.drawStr( 0, 13, "C1 position:");
    char buf[17];
    sprintf (buf, "%-3d", C1);
    u8g2.drawStr( 75, 13, buf);
    u8g2.drawStr( 0, 26, "approx uF:");
    //u8g2.drawStr( 0, 39, "any button or use");
    //u8g2.drawStr( 0, 52, "back button");
  } while ( u8g2.nextPage() );
  // Reset Button Value
  g_button_value = C1; 

}



void LCDML_DISP_loop(LCDML_FUNC_tuneC1)
{
  // loop function, can be run in a loop when LCDML_DISP_triggerMenu(xx) is set
  // the quit button works in every DISP function without any checks; it starts the loop_end function 
  
  if (LCDML_BUTTON_checkAny()) {
    if (LCDML_BUTTON_checkDown()) {
      // check if button up is pressed -- even though it says 'down'
      LCDML_BUTTON_resetDown(); // reset the down button
      g_button_value++;
      
      // update lcd content
      char buf[4];
      sprintf (buf, "%-3d", g_button_value);
      
      //u8g2.setFont(_LCDML_DISP_font);
      //u8g2.firstPage();  
      do {
        //print the value
        u8g2.drawStr( 75, 13, buf);
        u8g2.drawBox(9, 50, g_button_value, 13);
      } while( u8g2.nextPage() );        
    } //if checkDown   
    
    if (LCDML_BUTTON_checkUp()) {
      LCDML_BUTTON_resetUp();
      g_button_value--;
      // update lcd content
      char buf[17];
      sprintf (buf, "%-3d", g_button_value);
      
      //u8g2.setFont(_LCDML_DISP_font);
      //u8g2.firstPage();  
      do {
        //print the value
        u8g2.drawStr( 75, 13, buf);
        u8g2.setDrawColor(0);
        u8g2.drawBox((10+g_button_value),51,(99-g_button_value),11);
        //u8g2.drawBox(9, 50, g_button_value, 13);
        u8g2.setDrawColor(1);
      } while( u8g2.nextPage() );  

      C1 = g_button_value;

    }
  } //if checkAny
  
  // check if button count is three
  if (g_button_value >= 20) {
    // end function for callback
    LCDML_DISP_funcend();   
  } 
}



void LCDML_DISP_loop_end(LCDML_FUNC_tuneC1)
{
  // this functions is ever called when a DISP function is quit
  // you can here reset some global vars or do nothing
}
