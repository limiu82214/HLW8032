#ifndef HLW8032_h
#define HLW8032_h


#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
//#include "Variable.h"

class HLW8032
{
	public:
		HLW8032();
		void begin(HardwareSerial& SerialData);
		void SerialReadLoop();  //串口循环业务 获取数据，并且解码数据
		void test();
		float GetVol();   // 获取电压
		float GetCurrent();  //获取电流
		float GetPower();   //获取有功功率
		uint16_t GetPF();   //获取电脉冲计数器
		uint32_t GetPFAll();   //获取总脉冲数
		float GetKWh();  // 获取总电量
		
	private:
	
		bool Checksum();   //校验函数
		
		byte SerialTemps[64] ;  //串口缓冲区
		byte SeriaDataLen =0;  //数据长度计数器
		HardwareSerial *SerialID;
		
		uint8_t SysStatus;  //系统状态寄存器
		uint32_t VolPar;   //电压参数
		uint32_t VolData;   //电压数据
		uint32_t CurrentPar; 		//电流参数
		uint32_t CurrentData; 		//电流数据
		uint32_t PowerPar;         //功率参数
		uint32_t PowerData;        //功率数据
		uint16_t PF;               //脉冲计数器
		uint32_t PFData;           //脉冲溢出计数器
		uint32_t VolR1 = 1880000;    //电压电阻1 470K*4  1880K
		uint32_t VolR2 = 1000;        //电压电阻2  1K
		float CurrentRF = 0.1;       // 电流采样电阻 0.1
};


#endif