// Link: http://oj.csie.ndhu.edu.tw/problem/PR110-2Q37
class RemoveFromBig : public Container {
	public:
		int remove() {
			int j;
			if(index == 0)
				return 0;
			int max = data[0];
			int indexMax;
			for(j = 0; j < index; j ++) {
				if(data[j] >= max) {
					max = data[j];
					indexMax = j;
				}
			}
			for(j = indexMax; j < index - 1; j++) {
				data[j] = data[j+1];
			}
			index--;
			return max;
		}
};

class RemoveFromSmall: public Container {
	public:
		int remove() {
			int j;
			if(index == 0)
				return 0;
			int min = 999999999;
			int indexMin;
			for(j = 0; j < index; j ++) {
				if(data[j] < min) {
					min = data[j];
					indexMin = j;
				}
			}
			for(j = indexMin; j < index - 1; j++) {
				data[j] = data[j+1];
			}
			index--;
			return min;
		}
};
