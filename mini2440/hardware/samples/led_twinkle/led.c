#define	GPBCON	(*(volatile unsigned long *)0x56000010)
#define	GPBDAT	(*(volatile unsigned long *)0x56000014)

#define	GPB5_out	(1<<(5*2))

#define DELAY_TIME	0x3ffff

#define LED_ON	0x00000000 /* �ĸ�LED��Ӧ�Ĺܽ�ȫ������Ϊ�͵�ƽ */
#define LED_OFF	0x000001e0 /* �ĸ�LED��Ӧ�Ĺܽ�ȫ������Ϊ�ߵ�ƽ */

void  delay(unsigned long dly)
{
	for(; dly > 0; dly--);
}

int main(int argc, char *argv[])
{
	// ��LED1��Ӧ��GPB5����������Ϊ���
	GPBCON = GPB5_out;

	while (1) {
		GPBDAT = LED_ON;
		delay(DELAY_TIME);
		
		GPBDAT = LED_OFF;
		delay(DELAY_TIME);
	}

	return 0;
}
