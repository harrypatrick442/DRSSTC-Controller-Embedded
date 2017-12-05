/*
* Outputs.h
*
* Created: 08/10/2017 12:15:44
* Author: SoftwareEngineer
*/


#ifndef __OUTPUTS_H__
#define __OUTPUTS_H__


class Outputs
{
	//variables
	public:
	static void Initialize();
	class PB{
		public:
		class _5{
			public:
			static void SetHigh();
			static void SetLow();
		};

	};
	class PD{
		public:
		class _2{
			public:
			static void SetHigh();
			static void SetLow();
		};
		class _3{
			public:
			static void SetHigh();
			static void SetLow();
		};
		class _4{
			public:
			static void SetHigh();
			static void SetLow();
		};

	};
	protected:
	private:

	//functions
	public:
	Outputs();
	~Outputs();
	protected:
	private:
	Outputs( const Outputs &c );
	Outputs& operator=( const Outputs &c );

}; //Outputs

#endif //__OUTPUTS_H__
