
#ifndef EVENTBUS_H_
#define EVENTBUS_H_

#include <event_queue.hpp>
#include <flat.h>

class EventBus
{
  public:
	static EventBus& getInstance(void)
	{
		static EventBus mBus;
		return mBus;
	}

	void subscribe();
	void push(flat2d::Entity entity) { entityQueue.push(entity); }

  private:
	EventBus(void) {}
	~EventBus(void) {}

	wink::event_queue<flat2d::Entity> entityQueue;

	EventBus(EventBus const&) = delete;
	void operator=(EventBus const&) = delete;
};

#endif
