#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LED_MAX_NAME_SIZE 128
typedef unsigned char u8;
void DumpBuffer(unsigned char *buf, int bufSize);
void DumpBuffer(unsigned char *buf, int bufSize)
{
    int i = 0;
 
    printf("buffer size is %d \n", bufSize);
    for (i=0; i<bufSize;i++ ){
        printf("buf[%d] = %d (%c) ", i, buf[i], buf[i]);
        if ( (i != 0) && (i % 5 == 0))
        {
            printf("\n");
        }
    }
 
    printf("\n\n");
}


#if 1
typedef enum{
    LED1_R = 0,
    LED1_G,
    LED1_B,
    LED2_R,
    LED2_G,
    LED2_B
}STM32_LEDS;

typedef struct{
	u8 blink_rate;
	u8 brightness;
}one_led;

typedef struct _stm32_cmd_f{
	union {
		struct{
			u8 CMD;
			u8 CMD_SIZE;
			union{
				u8 aLed[12];
				struct {
					one_led Led1R;
					one_led Led1G;
					one_led Led1B;
					one_led Led2R;
					one_led Led2G;
					one_led Led2B;
				};
			};
			u8 reserve[18]; // 32-2-12 = 18
		};
		u8 buf[32];
	};
} stm32_cmd_f;
#endif

void spi_stm32_brightness_set(STM32_LEDS led, u8 brightness)
{
	u8 Led_offset= led*2 + 1;
	stm32_cmd_f data;
	memset(&data, 0, sizeof(data));
	data.aLed[Led_offset]=brightness;
	DumpBuffer( (unsigned char *)&data, sizeof(data));
}


int f1(void)
{
	stm32_cmd_f data;
	memset(&data, 0, sizeof(data));
	//data.CMD=3;
	//data.Led1R.blink_rate=200;
	//data.Led1R.blink_rate=200;
	//data.buf[2]=200;
	//DumpBuffer( (unsigned char *)&data, sizeof(data));
	spi_stm32_brightness_set(LED2_B, 120);
	return 0;
}

int main(int argc, char *argv[])
{

	f1();
	return 0;
   
}

