#include "push_swap.h"

int calculate_move_extract(k_list *stack, int nbr, t_move *current)
{
	k_list *head;
	int position;
	int size;

	head = stack;
	position = 0;
	size = 0;

	while (head)
	{
		size++;
		head = head->next;
	}
	head = stack;
	while (head && nbr != head->content)
	{
		position++;
		head = head->next;
	}
	if ((size - position) < position)
	{
		current->rra = (size - position); 
		return (size - position);
	}
	current->ra = position; 
	return position;
}

int find_first_smallest(k_list *stack, int nbr)
{
	int next_smallest;

	next_smallest = nbr;
	while (stack)
	{
		if (stack->content < nbr)
		{
			next_smallest = stack->content;
			break;
		}
		stack = stack->next;
	}
	return next_smallest;
}

int find_biggest(k_list *stack, int nbr)
{
	int biggest;

	biggest = nbr;
	while (stack)
	{
		if (stack->content > nbr && stack->content > biggest)
			biggest = stack->content;
		stack = stack->next;
	}
	return biggest;
}

int find_next_smallest(k_list *stack, int smallest, int nbr)
{
	while (stack)
	{
		if (stack->content < nbr && stack->content > smallest)
			smallest = stack->content;
		stack = stack->next;
	}
	return smallest;
}

int get_move(k_list *stack, int nbr, t_move *current)
{
	int position;
	int size;

	position = 0;
	size = get_stack_size(stack);
	while (stack && stack->content != nbr)
	{
		position++;
		stack = stack->next;
	}
	if ((size - position) < position)
	{
		current->rrb = (size - position);
		return (size - position);
	}
		current->rb = position;
	return position; 
}

int calculate_move_insert(k_list *stack, int nbr, t_move *current)
{
	k_list *head;
	int smallest;
	int biggest;
	int move;

	head = stack;
	smallest = find_first_smallest(stack, nbr);
	biggest = find_biggest(stack, nbr);

	// printf("FIRST SMALL=%d\n", smallest);

	if (smallest != nbr)
	{
		smallest = find_next_smallest(stack, smallest, nbr);
		move = get_move(stack, smallest, current);
		// printf("BIGGEST SMALL=%d\n", smallest);
	}
	else
	{
		move = get_move(stack, biggest, current);
		// printf("BIGGEST=%d\n", biggest);
	}
	// printf("POS=%d\n", move);
	// printf("REVERSE=%d\n", check_is_reverse_better(stack, smallest));
	return move;
}

void init_struct(t_move *current)
{
	current->rra = 0;
	current->ra = 0;
	current->rrr = 0;
	current->rr = 0;
	current->rrb = 0;
	current->rb = 0;
	current->total = 0;
}

int get_total_move(t_move *current)
{
	int total;

	total = current->rra + current->ra + current->rrr + current->rr + current->rrb + current->rb;
	current->total = total;
	return total;
}

void rrr_check(t_move *current)
{
	while (current->ra >= 1 && current->rb >= 1)
	{
		current->ra--;
		current->rb--;
		current->rr++;
	}
	while (current->rra >= 1 && current->rrb >= 1)
	{
		current->rra--;
		current->rrb--;
		current->rrr++;
	}
}

t_move calculate_move_total(k_list *stack_a, k_list *stack_b, int biggest, int second_biggest, int third_biggest)
{
	k_list *head = stack_a;
	int insert = 0;
	int insertbest = 0;
	int extract = 0;
	int extractbest = 0;
	t_move current;
	t_move best;

	init_struct(&best);
	best.rra = 2147483647;
	while (stack_a)
	{
		init_struct(&current);
		current.nbr = stack_a->content;
		extract = calculate_move_extract(head, stack_a->content, &current);
		insert = calculate_move_insert(stack_b, stack_a->content, &current);
		rrr_check(&current);
		if (get_total_move(&current) < get_total_move(&best) && stack_a->content != biggest 
		&& stack_a->content != second_biggest && stack_a->content != third_biggest)
		{
			best = current;
			insertbest = insert;
			extractbest = extract;
		}
		// printf("%d extract=%d insert=%d\n", stack_a->content, extract, insert);
		stack_a = stack_a->next;
		// printf("NBR=%d RRA=%d RA=%d RR=%d RRB=%d RB=%d RRR=%d TOTAL=%d\n\n", current.nbr, current.rra, current.ra, current.rr, current.rrb, current.rb, current.rrr, current.total);
	}
	// printf("BEST=%d extract=%d insert=%d TOTAL=%d\n", best.nbr, extractbest, insertbest, best.total);
	// printf("BEST=%d\n", best.nbr);
	return best;
}

//487 59 492 196 463 486 146 301 233 13 304 37 228 392 440 1 153 260 450 474 274 394 342 401 404 426 133 276 163 132 46 405 424 88 127 2 328 346 94 208 339 356 406 136 466 12 137 182 193 275 432 336 180 456 324 188 205 467 244 254 317 354 16 364 93 73 113 429 376 21 448 135 375 320 470 379 229 106 148 278 9 253 265 236 280 243 246 45 49 139 165 255 371 87 25 110 491 245 403 172 335 338 476 332 329 154 66 168 261 307 125 259 237 26 272 415 192 488 6 116 79 248 211 38 319 361 418 343 451 430 98 187 402 109 496 24 314 473 234 458 395 53 384 419 373 437 345 39 494 422 143 218 269 323 71 221 100 331 124 316 325 22 230 118 184 30 74 454 44 40 363 350 217 443 210 119 161 48 256 202 457 173 4 201 334 158 469 85 70 279 285 439 142 388 238 28 408 435 400 292 186 273 333 144 407 162 311 391 131 465 235 482 76 151 475 455 207 52 203 445 231 62 115 397 220 174 242 300 412 240 294 82 215 377 341 68 223 313 185 32 252 189 56 126 216 298 462 130 61 264 495 19 498 268 257 134 47 295 50 441 72 398 348 461 195 358 266 421 433 219 427 381 367 5 318 436 322 90 366 108 96 80 483 374 442 271 86 114 31 428 75 385 181 102 251 288 287 42 315 121 471 169 140 194 191 81 327 129 145 369 107 372 58 420 41 290 247 262 258 296 212 239 270 11 249 499 7 500 112 299 34 431 493 490 438 460 477 241 123 321 479 434 164 67 35 370 281 286 446 399 117 480 128 389 393 160 360 209 310 3 206 291 149 99 55 409 78 396 306 411 91 308 357 159 263 166 141 17 105 57 380 472 349 383 481 33 344 417 51 284 386 18 65 413 197 175 378 120 204 155 222 449 362 69 478 150 355 232 359 382 198 103 410 464 10 177 60 303 330 347 101 157 199 340 423 54 183 176 92 20 352 326 167 111 351 365 89 468 190 453 63 444 337 497 293 226 170 312 179 200 213 387 122 138 447 277 414 156 8 227 43 309 224 225 302 489 425 36 15 14 83 282 368 353 29 250 214 485 283 390 297 64 77 416 27 452 104 171 97 178 147 84 267 95 23 459 484 289 152 305