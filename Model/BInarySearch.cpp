// 对于YES_LEFT或者NO_RIGHT
int bSearch(int begin, int end, int e)
{
	int mid, left = begin, right = end;
	while(left <= right)
	{
		mid = (left + right) >> 1;
		if(num[mid] >= e) right = mid - 1;
		else left = mid + 1;
	}
	return left;
}

// 对于YES_RIGHT或者NO_LEFT
int bSearch(int begin, int end, int e)
{
	int mid, left = begin, right = end;
	while(left <= right)
	{
		mid = (left + right) >> 1;
		if(num[mid] > e) right = mid - 1;
		else left = mid + 1;
	}
	return right;
}