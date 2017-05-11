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

namespace SortAlg { /// @todo Add compare func
	template <typename ITER>
	void OddEvenSort(ITER start, ITER end) {
		bool sorted = false;
		while(!sorted) {
			sorted = true;
			
			for(std::size_t i = 0; i < std::distance(start, end) - 1; i += 2) {
				if(*(start + i) > *(start + i + 1)) {
					std::iter_swap(start + i, start + i + 1);
					sorted = false;
				}
			}
			
			for(std::size_t i = 1; i < std::distance(start, end) - 1; i += 2) {
				if(*(start + i) > *(start + i + 1)) {
					std::iter_swap(start + i, start + i + 1);
					sorted = false;
				}
			}
		}
	}
}

namespace SortAlgVis {
	template <typename ITER>
	void OddEvenSort(ITER start, ITER end) {
		bool sorted = false;
		while(!sorted) {
			sorted = true;
			
			::gWindow->render({start});
			for(std::size_t i = 0; i < std::distance(start, end) - 1; i += 2) {
				::gWindow->render({start + i, start + i + 1});
				if(*(start + i) > *(start + i + 1)) {
					std::iter_swap(start + i, start + i + 1);
					::gWindow->render({start + i, start + i + 1});
					sorted = false;
				}
			}
			
			::gWindow->render({start});
			for(std::size_t i = 1; i < std::distance(start, end) - 1; i += 2) {
				::gWindow->render({start + i, start + i + 1});
				if(*(start + i) > *(start + i + 1)) {
					std::iter_swap(start + i, start + i + 1);
					::gWindow->render({start + i, start + i + 1});
					sorted = false;
				}
			}
		}
	}
}