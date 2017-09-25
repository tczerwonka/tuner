// font options
// u8g2_font_helvR08_tr through u8g2_font_helvR14_tr -- nice non-serif font

////////////////////////////////////////////////////////////////////////////////
// version / startup screen
////////////////////////////////////////////////////////////////////////////////
void version()
{
  //clear the screen
  u8g2.clearBuffer();
  //u8g2.setFont(u8g2_font_ncenB14_tr);
  u8g2.setFont(u8g2_font_helvR14_tr);
  u8g2.drawStr(18, 15, "Auto-Tuner");
  u8g2.setFont(u8g2_font_helvR08_tr);
  u8g2.drawStr(30, 30, "v0.01 Feb2017");
  u8g2.drawStr(15, 64, "T. Czerwonka WO9U");
  u8g2.setFont(u8g2_font_unifont_t_symbols);
  //u8g2.drawGlyph(55, 50, 0x2603);  /* dec 9731/hex 2603 Snowman */
  u8g2.drawGlyph(55, 50, 0x2615);  /* dec 9731/hex 2603 Snowman */
  // ... write something to the buffer
  u8g2.sendBuffer();
  //tone(BEEP, 440, 50);
  //tone(BEEP, 880, 50);
  //tone(BEEP, 2000, 50);

}



////////////////////////////////////////////////////////////////////////////////
// initial_setup()
//  function to initialize all devices to zero
//  Potentially:
//   * determine if last shutdown was 'clean'
//     possibly writing to nvram (good idea?) that positions are 'dirty' before
//     start of adjustment and then indicate they're 'clean' if a tune finishes
//     then just assume that no sticky fingers have been inside to tweak the 
//     locations from what the last settings indicate they should be
//   * if not clean, run locate_hardware()
////////////////////////////////////////////////////////////////////////////////
void initial_setup ()
{
}



////////////////////////////////////////////////////////////////////////////////
// locate_hardware()
//   function to step through both caps and inductor and determine positions
////////////////////////////////////////////////////////////////////////////////
void locate_hardware()
{
}



