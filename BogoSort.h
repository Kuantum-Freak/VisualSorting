/* 
 * Copyright (c) 2017 The Gupta Empire - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 *
 * Written by Aryan Gupta <me@theguptaempire.net>
 * 
 * =============================================================================
 * @author 			Aryan Gupta
 * @project 		
 * @title 			
 * @date			(YYYY-MM-DD)
 * @fversion		1.0.0
 * @description 	
 * =============================================================================
 */
#include "info.h"

namespace SortAlg {
	template <typename ITER>
	bool Sorted(ITER start, ITER end) {
		while(++start != end)
			if(*start < *(start - 1)) return false;
		return true;
	}
	
	template <typename ITER>
	void RandomShuffle(ITER start, ITER end) {
		unsigned num = std::distance(start, end);
		
		while(--num != 1) 
			std::iter_swap(start + (rand() % num), end - 1);
	}
	
	template <typename ITER>
	void BogoSort(ITER start, ITER end) {
		//srand(time(0));
		
		while(!Sorted(start, end))
			RandomShuffle(start, end);
	}
}


namespace SortAlgVis {
	template <typename ITER>
	bool Sorted(ITER start, ITER end) {
		while(++start != end) {
			::gWindow->render({start});
			if(*start < *(start - 1)) return false;
		}
		return true;
	}
	
	template <typename ITER>
	void RandomShuffle(ITER start, ITER end) {
		std::size_t size = std::distance(start, end);
		
		for(unsigned i = 0; i < size; ++i) {
			std::size_t s1 = rand() % size;
			std::size_t s2 = rand() % size;
			std::iter_swap(start + s1, end - s2 - 1);
			::gWindow->render({start + s1, end - s2 - 1});
		}
	}
	
	template <typename ITER>
	void BogoSort(ITER start, ITER end) {
		//srand(time(0));
		
		while(!Sorted(start, end)) {
			RandomShuffle(start, end);
			::gWindow->render();
		}
	}
}