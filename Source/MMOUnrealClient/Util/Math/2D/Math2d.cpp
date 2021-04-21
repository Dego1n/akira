// MMOClient 2019


#include "Math2d.h"

/**
 * @author Dego1n
 */
float Math2d::Find2dDistanceBetween3DVectors(FVector point1, FVector point2)
{
	return FMath::Sqrt(FMath::Square(point2.X - point1.X) + FMath::Square(point2.Y - point1.Y));
}
