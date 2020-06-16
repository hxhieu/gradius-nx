#ifndef ENTITYBASE_H_
#define ENTITYBASE_H_

#include <flat.h>

namespace gradiusnx {
	class EntityBase : public flat2d::Entity
	{

	  public:
		EntityBase(int x, int y)
		  : flat2d::Entity(0, 0, 64, 64)
		{
			setCenter(x, y);
		}
		int getCentreX(void)
		{
			return entityProperties.getXpos() + entityProperties.getWidth() / 2;
		}

		int getCentreY(void)
		{
			return entityProperties.getYpos() +
			       entityProperties.getHeight() / 2;
		}

		void setCenter(int x, int y)
		{
			entityProperties.setXpos(x - entityProperties.getWidth() / 2);
			entityProperties.setYpos(y - entityProperties.getHeight() / 2);
		}
	};
}
#endif // ENTITYBASE_H_
