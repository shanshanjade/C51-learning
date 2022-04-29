#include "REG52.H"

void UartInit(void)		//9600bps@11.0592MHz
{
	PCON &= 0x7F;		//�����ʲ�����
	SCON = 0x50;		//8λ����,�ɱ䲨����
	TMOD &= 0x0F;		//�����ʱ��1ģʽλ
	TMOD |= 0x20;		//�趨��ʱ��1Ϊ8λ�Զ���װ��ʽ
	TL1 = 0xFD;		//�趨��ʱ��ֵ
	TH1 = 0xFD;		//�趨��ʱ����װֵ
	ET1 = 0;		//��ֹ��ʱ��1�ж�
	TR1 = 1;		//������ʱ��1
	EA = 1;
	ES = 1;
}

void uart_Send_Byte(unsigned char byte){
    SBUF = byte;
    while (TI == 0);
    TI = 0;
}

void uart_Send_String(char*mystring){
	while (*mystring != '\0') {
		uart_Send_Byte(*mystring);
		mystring++;
	}
}

// void uart_Routine() interrupt 4 {
//     if (RI == 1)
//     {
//         temp = SBUF;
//         RI = 0;
//     }
// }