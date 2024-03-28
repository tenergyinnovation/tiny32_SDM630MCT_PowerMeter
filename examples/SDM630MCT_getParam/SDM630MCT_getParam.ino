/***********************************************************************
 * Project      :     SDM630MCT_getParam
 * Description  :     Get Parameter for SDM630MCT 3-Phase Modbus RTU power meter module
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

uint8_t id = 1; //Address if SDM630MCT, You can change here if it differance

float p1_volt,p2_volt,p3_volt;
float p1_current,p2_current,p3_current;
float p1_watt,p2_watt,p3_watt;
float p1_va,p2_va,p3_va;
float p1_var,p2_var,p3_var;
float p1_pf,p2_pf,p3_pf;
float freq;
float sum_current;
float total_watt;
float total_va;
float total_var;


void setup()
{
  Serial.begin(115200);
  Serial.printf("\r\n**** SDM630MCT_getParam ****\r\n");
  mcu.SDM630MCT_begin(RXD2,TXD2);
  vTaskDelay(3000);
  mcu.buzzer_beep(2); //buzzer 2 beeps
  mcu.library_version();
}

void loop()
{

    /* Read Phase 1 line to neutral volts. */
    p1_volt = mcu.SDM630MCT_P1_Volt(id);
    if(p1_volt != -1)
    {
      Serial.printf("Info: p1_volt = %.2fV\r\n",p1_volt);
    }
    else
    {
      Serial.printf("Error: can't read p1_volt!!\r\n");
    }

    /* Read Phase 2 line to neutral volts. */
    p2_volt = mcu.SDM630MCT_P2_Volt(id);
    if(p2_volt != -1)
    {
      Serial.printf("Info: p2_volt = %.2fV\r\n",p2_volt);
    }
    else
    {
      Serial.printf("Error: can't read p2_volt!!\r\n");
    }

   /* Read Phase 3 line to neutral volts. */
    p3_volt = mcu.SDM630MCT_P3_Volt(id);
    if(p3_volt != -1)
    {
      Serial.printf("Info: p3_volt = %.2fV\r\n",p3_volt);
    }
    else
    {
      Serial.printf("Error: can't read p3_volt!!\r\n");
    }
    Serial.println();

      /* Read Phase 1 current */
    p1_current = mcu.SDM630MCT_P1_Current(id);
    if(p1_current != -1)
    {
      Serial.printf("Info: p1_current = %.2f A\r\n",p1_current);
    }
    else
    {
      Serial.printf("Error: can't read p1_current!!\r\n");
    }

    /* Read Phase 2 current */
    p2_current = mcu.SDM630MCT_P2_Current(id);
    if(p2_current != -1)
    {
      Serial.printf("Info: p2_current = %.2f A\r\n",p2_current);
    }
    else
    {
      Serial.printf("Error: can't read p2_current!!\r\n");
    }

   /* Read Phase 3 current */
    p3_current = mcu.SDM630MCT_P3_Current(id);
    if(p3_current != -1)
    {
      Serial.printf("Info: p3_current = %.2f A\r\n",p3_current);
    }
    else
    {
      Serial.printf("Error: can't read p3_current!!\r\n");
    }
    Serial.println();


  /* Read Phase 1 active power. (W) */
    p1_watt = mcu.SDM630MCT_P1_Watt(id);
    if(p1_watt != -1)
    {
      Serial.printf("Info: p1_watt = %.2f W\r\n",p1_watt);
    }
    else
    {
      Serial.printf("Error: can't read p1_watt!!\r\n");
    }

    /* Read Phase 2 active power. (W) */
    p2_watt = mcu.SDM630MCT_P2_Watt(id);
    if(p2_watt != -1)
    {
      Serial.printf("Info: p2_watt = %.2f W\r\n",p2_watt);
    }
    else
    {
      Serial.printf("Error: can't read p2_watt!!\r\n");
    }

   /* Read Phase 3 active power. (W) */
    p3_watt = mcu.SDM630MCT_P3_Watt(id);
    if(p3_watt != -1)
    {
      Serial.printf("Info: p3_watt = %.2f W\r\n",p3_watt);
    }
    else
    {
      Serial.printf("Error: can't read p3_watt!!\r\n");
    }
    Serial.println();


  /* Read Phase 1 apparent power. (VA) */
    p1_va = mcu.SDM630MCT_P1_VA(id);
    if(p1_va != -1)
    {
      Serial.printf("Info: p1_va = %.2f VA\r\n",p1_va);
    }
    else
    {
      Serial.printf("Error: can't read p1_va!!\r\n");
    }

    /* Read Phase 2 apparent power. (VA) */
    p2_va = mcu.SDM630MCT_P2_VA(id);
    if(p2_va != -1)
    {
      Serial.printf("Info: p2_va = %.2f VA\r\n",p2_va);
    }
    else
    {
      Serial.printf("Error: can't read p2_va!!\r\n");
    }

   /* Read Phase 3 apparent power. (VA)) */
    p3_va = mcu.SDM630MCT_P3_VA(id);
    if(p3_va != -1)
    {
      Serial.printf("Info: p3_va = %.2f VA\r\n",p3_va);
    }
    else
    {
      Serial.printf("Error: can't read p3_va!!\r\n");
    }
    Serial.println();

      /* Read Phase 1 reactive power. (VAr) */
    p1_var = mcu.SDM630MCT_P1_VAr(id);
    if(p1_var != -1)
    {
      Serial.printf("Info: p1_var = %.2f VAr\r\n",p1_var);
    }
    else
    {
      Serial.printf("Error: can't read p1_var!!\r\n");
    }

    /* Read Phase 2 reactive power. (VAr) */
    p2_var = mcu.SDM630MCT_P2_VAr(id);
    if(p2_var != -1)
    {
      Serial.printf("Info: p2_var = %.2f VAr\r\n",p2_var);
    }
    else
    {
      Serial.printf("Error: can't read p2_var!!\r\n");
    }

   /* Read Phase 3 reactive power. (VAr) */
    p3_var = mcu.SDM630MCT_P3_VAr(id);
    if(p3_var != -1)
    {
      Serial.printf("Info: p3_var = %.2f VAr\r\n",p3_var);
    }
    else
    {
      Serial.printf("Error: can't read p3_var!!\r\n");
    }
    Serial.println();


  /* Read Phase 1 power factor */
    p1_pf = mcu.SDM630MCT_P1_PF(id);
    if(p1_pf != -1)
    {
      Serial.printf("Info: p1_pf = %.2f \r\n",p1_pf);
    }
    else
    {
      Serial.printf("Error: can't read p1_pf!!\r\n");
    }

    /* Read Phase 2 power factor */
    p2_pf = mcu.SDM630MCT_P2_PF(id);
    if(p2_pf != -1)
    {
      Serial.printf("Info: p2_pf = %.2f \r\n",p2_pf);
    }
    else
    {
      Serial.printf("Error: can't read p2_pf!!\r\n");
    }

   /* Read Phase 3 power factor */
    p3_pf = mcu.SDM630MCT_P3_PF(id);
    if(p3_pf != -1)
    {
      Serial.printf("Info: p3_pf = %.2f \r\n",p3_pf);
    }
    else
    {
      Serial.printf("Error: can't read p3_pf!!\r\n");
    }
    Serial.println();


  /* Read Frequency (Hz) */
    freq = mcu.SDM630MCT_Freq(id);
    if(freq != -1)
    {
      Serial.printf("Info: freq = %.2f Hz\r\n",freq);
    }
    else
    {
      Serial.printf("Error: can't read freq!!\r\n");
    }

    /* Read Sum of line currents.(A) */
    sum_current = mcu.SDM630MCT_Sum_Current(id);
    if(sum_current != -1)
    {
      Serial.printf("Info: sum_current = %.2f A\r\n",sum_current);
    }
    else
    {
      Serial.printf("Error: can't read sum_current!!\r\n");
    }

    /* Read Total system power.(W) */
    total_watt = mcu.SDM630MCT_Total_Watt(id);
    if(total_watt != -1)
    {
      Serial.printf("Info: total_watt = %.2f W\r\n",total_watt);
    }
    else
    {
      Serial.printf("Error: can't read total_watt!!\r\n");
    }

    /* Read Total system volt amps.(VA) */
    total_va = mcu.SDM630MCT_Total_VA(id);
    if(total_va != -1)
    {
      Serial.printf("Info: total_va = %.2f VA\r\n",total_va);
    }
    else
    {
      Serial.printf("Error: can't read total_va!!\r\n");
    }

    /* Read Total system VAr. */
    total_var = mcu.SDM630MCT_Total_VAr(id);
    if(total_var != -1)
    {
      Serial.printf("Info: total_var = %.2f VAr\r\n",total_var);
    }
    else
    {
      Serial.printf("Error: can't read total_var!!\r\n");
    }



    Serial.println("********************************\r\n");
  
    vTaskDelay(5000);

}


