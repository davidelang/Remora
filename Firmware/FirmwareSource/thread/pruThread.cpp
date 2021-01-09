#include "pruThread.h"
#include "modules/module.h"


using namespace std;

// Thread constructor
pruThread::pruThread(LPC_TIM_TypeDef* timer, IRQn_Type irq, uint32_t frequency) :
	timer(timer),
	irq(irq),
	frequency(frequency)
{
	printf("Creating thread %d\n", this->frequency);
}

void pruThread::startThread(void)
{
	TimerPtr = new pruTimer(this->timer, this->irq, this->frequency, this);
}

void pruThread::registerModule(Module* module)
{
	this->vThread.push_back(module);
}

void pruThread::run(void)
{
	// iterate over the Thread pointer vector to run all instances of Module::runModule()
	for (iter = vThread.begin(); iter != vThread.end(); ++iter) (*iter)->runModule();
}
