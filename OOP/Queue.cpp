// Link: http://oj.csie.ndhu.edu.tw/problem/PR110-2Q27
class queue : public container {
	public:
		queue(int len) : container(len), index(-1) {}
		bool put_in(int);
		int *take_out(void);

	protected:
		int index;
};

class priority_queue : public queue {
	public:
		priority_queue(int len, bool f) : queue(len), order(f) {}
		bool put_in(int);
		int *take_out(void);

	private:
		bool order;
};

bool queue::put_in(int obj) {
	if (index == len - 1) {
		return false;
	}
	box[++index] = obj;
	return true;
}

int *queue::take_out() {
	if (index == -1) {
		return NULL;
	}
	int *temp = new int[1];
	temp[0] = box[0];
	for (int i = 0; i < index; i++) {
		box[i] = box[i + 1];
	}
	index--;
	return temp;
}

bool priority_queue::put_in(int obj) {
	return queue::put_in(obj);
}

int *priority_queue::take_out(void) {
	if (index == -1) {
		return NULL;
	}
	int *max = new int[1], *min = new int[1];
	int max_i = 0, min_i = 0;
	max[0] = min[0] = box[0];
	for (int i = 0; i <= index; i++) {
		if (box[i] > max[0]) {
			max[0] = box[i];
			max_i = i;
		}
		if (box[i] < min[0]) {
			min[0] = box[i];
			min_i = i;
		}
	}
	for (int i = order ? max_i : min_i; i < index; i++) {
		box[i] = box[i + 1];
	}
	index--;
	return order ? max : min;
}
