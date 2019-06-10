
#include <utility>
#include <algorithm>

#define ALL(a) (a).begin(), (a).end()
#define llong long long

using namespace std;
template <class BidirectionalIterator>
bool next_combination(BidirectionalIterator first1,
		BidirectionalIterator last1,
		BidirectionalIterator first2,
		BidirectionalIterator last2)
{
	if ((first1 == last1)||(first2 == last2)){
		return false;
	}
	BidirectionalIterator m1 = last1 ;
	BidirectionalIterator m2 = last2 ; --m2;
	while(--m1 != first1 && !(*m1 < *m2)) {
	}
	bool result = (m1 == first1) && !(*first1 < *m2);
	if(!result){
		while(first2 != m2 && !(*m1 < *first2)){
			++first2;
		}
		first1 = m1;
		std::iter_swap(first1 ,first2);
		++first1;
		++first2;
	}
	if((first1 != last1)&&(first2 != last2)){
		m1 = last1; m2 = first2;
		while((m1 != first1)&&(m2 != last2)){
			std::iter_swap(--m1 ,m2);
			++m2;
		}
		std::reverse(first1 ,m1);
		std::reverse(first1 ,last1);
		std::reverse(m2 , last2);
		std::reverse(first2 , last2);
	}
	return !result;
}

template <class BidirectionalIterator>
bool next_combination(BidirectionalIterator begin, BidirectionalIterator end, size_t r){
	return next_combination(begin, std::next(begin, r), std::next(begin, r), end);
}
template <class BidirectionalIterator>
bool next_combination(BidirectionalIterator begin, BidirectionalIterator middle, BidirectionalIterator end){
	return next_combination(begin, middle, middle, end);
}

signed main(){
	vector<int> a(10);
	int i = 0;
	for(auto &e : a)e = i++;
	i = 0;
	do{
		for(auto e : a)cout << e << " ";
		cout << endl;
		i++;
	}while(next_combination(ALL(a), 3));
	cout << i << endl;

	return 0;
}

