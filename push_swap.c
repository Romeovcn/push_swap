#include "push_swap.h"

int check_is_reverse_better(k_list *stack, int nbr)
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
		return 1;
	return 0; 	
}

void extract(k_list **stack, int nbr, int *action_count)
{
	int move;

	move = calculate_move_extract(*stack, nbr);
	if (check_is_reverse_better(*stack, nbr))
		while (move--)
		{
			rra(stack, *stack, action_count);
			// printf("REVERSE\n");
		}
	else
		while (move--)
		{
			ra(stack, *stack, action_count);
			// printf("NOT REVERSE\n");
		}
}

void insert_part_2(k_list **stack, int nbr, int move, int *action_count)
{
	if (check_is_reverse_better(*stack, nbr))
	while (move--)
		rrb(stack, *stack, action_count);
	else
		while (move--)
			rb(stack, *stack, action_count);
}

void insert(k_list **stack, int nbr, int *action_count)
{
	int smallest;
	int biggest;
	int move;

	smallest = find_first_smallest(*stack, nbr);
	biggest = find_biggest(*stack, nbr);
	if (smallest != nbr)
	{
		smallest = find_next_smallest(*stack, smallest, nbr);
		move = get_move(*stack, smallest);
		insert_part_2(stack, smallest, move, action_count);
	}
	else
	{
		move = get_move(*stack, biggest);
		insert_part_2(stack, biggest, move, action_count);
	}
}

int get_biggest(k_list *stack)
{
	int biggest;

	biggest = -2147483648;
	while (stack)
	{
		if (stack->content > biggest)
			biggest = stack->content;
		stack = stack->next;
	}
	return biggest;
}

int get_second_biggest(k_list *stack, int biggest)
{
	int second_biggest;

	second_biggest = -2147483648;
	while (stack)
	{
		if (stack->content > second_biggest && stack->content < biggest)
			second_biggest = stack->content;
		stack = stack->next;
	}
	return second_biggest;
}

int get_smallest(k_list *stack)
{
	int smallest;

	smallest = 2147483647;
	while (stack)
	{
		if (stack->content < smallest)
			smallest = stack->content;
		stack = stack->next;
	}
	return smallest;
}

int	main(void)
{
	k_list	*stack_a;
	k_list	*stack_b;
	int action_count;
	int best;
	int biggest;
	int second_biggest;
	int smallest;

	action_count = 0;
	stack_a = get_stack("80 51 98 -212 -40 -127 209 176 -138 0 110 139 68 -200 239 248 138 -75 -171 -168 49 -39 62 75 129 -20 92 -70 -85 148 185 224 -23 198 -29 161 188 -71 -15 174 -7 -21 120 42 -119 55 -208 -128 -64 170 -124 -248 -231 150 227 -247 54 203 118 78 -179 96 168 30 56 41 194 -234 35 103 -228 -18 181 223 -191 -198 -162 5 -34 -166 -243 -219 82 246 17 -165 -239 196 23 114 -249 104 60 134 106 61 -174 -102 25 122 -30 -66 52 88 202 -201 34 -226 -184 178 244 57 191 -209 2 32 47 121 147 -235 245 6 175 159 -5 -46 112 -151 -238 -120 -206 -1 -56 162 -105 -203 149 -233 -90 -149 -161 229 179 -160 226 -143 124 -211 158 -213 -245 -96 -52 -189 -144 221 -33 201 3 -41 -4 216 1 238 -157 -180 208 100 -72 -82 -246 -217 91 69 -94 -110 65 -223 -3 173 -47 -205 243 164 214 -170 -51 126 14 157 -25 -169 230 116 -95 193 155 -155 200 93 192 -68 -57 94 -86 15 -207 -177 -236 -32 -62 -83 -158 -116 -114 -232 -101 -221 -79 -61 -145 -122 -13 215 206 29 128 154 204 97 -227 225 -36 -12 -58 83 145 66 -134 222 -229 -99 -24 143 -218 -111 160 -242 -73 48 -195 207 115 249 45 131 89 240 167 -112 151 -63 37 -196 -11 -88 -225 -126 -100 99 63 117 -81 -115 -135 -59 26 -202 125 -175 -147 135 -43 -220 59 -193 -183 105 27 -146 -98 232 39 76 -54 247 -139 205 -103 -76 210 -14 7 190 177 -55 46 234 153 -6 -133 -167 12 -141 -153 132 86 -240 -50 -194 231 -65 136 90 -137 -159 -113 4 -142 -216 38 -173 250 187 -152 -28 123 -154 -123 -129 -37 -104 20 -108 71 130 -2 -84 -199 -241 -176 141 -106 18 -117 182 -26 -163 237 183 140 144 -91 -97 81 -131 -31 -87 24 -136 241 -185 -27 -215 111 40 -222 -44 228 218 85 142 -181 197 -214 107 74 -107 195 -164 -130 102 169 189 219 165 -48 77 108 152 211 -156 67 -67 -74 -187 127 -69 -140 87 -45 -78 101 21 171 8 -172 19 -244 156 -35 -210 -250 11 233 72 -22 133 -190 70 217 137 166 53 235 28 50 146 10 199 184 -60 242 64 -42 79 31 180 109 163 -148 43 84 119 58 -188 -8 -125 -92 -182 44 -121 33 220 -118 -89 -16 -10 -93 13 -237 -197 -230 -109 -17 36 -38 73 95 212 -186 213 -150 236 -132 -9 -204 113 -224 -53 -49 22 -178 186 9 172 -77 16 -80 -192");
	stack_b = get_stack("");
	biggest = get_biggest(stack_a);
	second_biggest = get_second_biggest(stack_a, biggest);
	// stack_b_list = NULL;

	// while (get_stack_size(stack_a_list) != 2)

	// ra(&stack_a_list, stack_a_list, &action_count);
	// pb(&stack_a_list, &stack_b_list, &action_count);
	// rb(&stack_b_list, stack_b_list, &action_count);
	// sa(stack_a_list, &action_count); // swap a1 a2

	// pa(&stack_a_list, &stack_b_list, &action_count);


	// printf("extract=%d\n",calculate_move_extract(stack_a_list, 4));
	// printf("insert=%d\n",calculate_move_insert(stack_b_list, 54));
	// calculate_move_insert(stack_b_list, 0);
		// printf("%d", biggest);


	while (get_stack_size(stack_a) != 400)
	{
		best = calculate_move_total(stack_a, stack_b, biggest, second_biggest);
		extract(&stack_a, best, &action_count);
		insert(&stack_b, best, &action_count);
		pb(&stack_a, &stack_b, &action_count);
	}

	// biggest = get_biggest(stack_b);
	// if (stack_a->content >stack_a->next->content)
	// 	sa(stack_a, &action_count);
	// if (check_is_reverse_better(stack_b, biggest))
	// 	while (stack_b->content != biggest)
	// 		rrb(&stack_b, stack_b, &action_count);
	// else
	// 	while (stack_b->content != biggest)
	// 		rb(&stack_b, stack_b, &action_count);
	// while (get_stack_size(stack_b) != 0)
	// 	pa(&stack_a, &stack_b, &action_count);


	printf("COUNT=====%d\n", action_count);
	print_list(stack_a);
	print_list(stack_b);
	clear_list(&stack_a);
	clear_list(&stack_b);
}