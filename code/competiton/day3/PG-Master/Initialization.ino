void SET() {
  if (digitalRead(35) == LOW)
  {
    digitalWrite(11, HIGH);
    //------------set out sensors on green
    FO = analogRead(36);
    FI = analogRead(37);
    RO = analogRead(34);
    RI = analogRead(33);
    LO = analogRead(A21);
    LI = analogRead(A22);
    BO = analogRead(18);
    BI = analogRead(19);
    Read_Cmp();
    //      Read_bno();
    while (digitalRead(35) == LOW) {

    }

    //      setcmp = bnox;
    setcmp = Compass;
    NFO = FO + 65;
    NFI = FI + 60;
    NRO = RO + 80;
    NRI = RI + 70;
    NLO = LO + 70;
    NLI = LI + 50;
    NBO = BO + 190;
    NBI = BI + 60;
    eeprom_write();
  }
  digitalWrite(11, LOW);
}

void Bazi() {
  Compass2 = Compass2 / 10;
  if (yell > 180) yell = yell - 360;
  if (Compass2 > 180) Compass2 = Compass2 - 360;
}

//------------spin speed------------
signed int spin_speed(int divided_value, int added_value, int zero_degree)
{
  int compass_input = 0, compass_output = 0;
  if (flag == 0) {
    Read_Cmp();
    compass_input = Cmp ;
  }
  if (flag == 1) {
    col_ang();
    compass_input = GYa;
  }
  if ( compass_input >= zero_degree )
    compass_output = (compass_input / divided_value) + (added_value);
  else if (compass_input <= (-zero_degree) )
    compass_output = (compass_input) / divided_value - added_value;
  else
    compass_output = 0;
  return compass_output;
}
