#include <bits/stdc++.h>

#define ALL(a) (a).begin(), (a).end()
#define llong long long

using namespace std;
	
template<class ForwardItr>
void partial_rotate(const ForwardItr l_begin, const ForwardItr l_end, const ForwardItr r_begin, const ForwardItr r_end){
	if(l_begin == l_end || r_begin == r_end)return;
	if(l_end == r_begin){
		std::rotate(l_begin, r_begin, r_end);
		return;
	}
	
	ForwardItr read = r_begin;
	ForwardItr write = l_begin;

	while(next(write,2) != r_end){
		for(auto i = l_begin; i != r_end; ++i)cout << *i << " ";
		cout << endl;
		std::iter_swap(write++, read++);
		if(write == l_end) write = r_begin;
		if(read == r_end){
			if(std::next(write) == read)break;
			read = std::next(write);
		}
		if(read == l_end) read = r_begin;
	}

}
template<class BidirectionalItr>
bool next_combination(const BidirectionalItr begin, const BidirectionalItr end, const size_t r){
	auto target = std::upper_bound(begin, next(begin,r), *prev(end));
	if(target != begin)--target;
	if(target == begin && *target >= *std::prev(end)){
		std::rotate(begin, begin+r, end);
		return false;
	}

	auto nxt = std::upper_bound(std::next(begin,r), end, *target);
	std::swap(*target, *nxt);
	++target; ++nxt;
	if(target != std::next(begin, r) && !(*next(begin,r-1) < *std::prev(end))){
		//cerr << distance(begin, target) << " " << distance(begin, next(begin, r)) << " " << distance(begin, nxt) << " " << distance(begin, end) << endl;
		partial_rotate(target, std::next(begin,r), nxt, end);
	}

	return true;
}

int main(){
	std::vector<int> a = {0,6,7,1,2,3,4,5};
	next_combination(ALL(a), 3);
	for(auto e : a)cout << e << " ";
	cout << endl;
	
	return 0;
}
