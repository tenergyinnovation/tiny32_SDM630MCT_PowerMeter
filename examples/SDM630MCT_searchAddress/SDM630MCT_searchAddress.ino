/***********************************************************************
 * Project      :     SDM630MCT_searchAddress
 * Description  :     Search Address for SDM630MCT 3-Phase Modbus RTU power meter module
 * Hardware     :     tiny32         
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     28/03/2024
 * Revision     :     1.0
 * Rev1.0       :     Original
 * website      :     http://www.tenergyinnovation.co.th
 * Email        :     uten.boonliam@tenergyinnovation.co.th
 * TEL          :     +66 82-308-3299
 ***********************************************************************/
#include <Arduino.h>
#include <tiny32_v3.h> //for tiny32 v3


tiny32_v3 mcu; //define object

void setup()
{
  Serial.begin(115200);
  Serial.printf("\r\n**** SDM630MCT_searchAddress ****\r\n");
  mcu.SDM120CT_begin(RXD2,TXD2);
  vTaskDelay(3000);
  mcu.buzzer_beep(2); //buzzer 2 beeps
  mcu.library_version();
}

void loop()
{

  uint8_t _id;
  
  _id = mcu.SDM630MCT_searchAddress();

  /* check result status */
  if(_id != -1)
  {
    Serial.printf("\r\nInfo: Address => %d\r\n",_id);
  }
  else
  {
    Serial.printf("\r\nError: Can't search address\r\n");
  }

  while(1);

}