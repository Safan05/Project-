#include"EarthGunnery.h"

EarthGunnery::EarthGunnery()
{
	Gcount = 0;
}

bool EarthGunnery::EnqueueEGunnery(const unit& t)
{
	return EGunnery.enqueue(t);
}
