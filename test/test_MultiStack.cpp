#include "MultiStack.h"

#include <gtest.h>

TEST(MultiStack, can_create_MultiStack_with_positive_length_and_positive_stackcount)
{
	ASSERT_NO_THROW(MultiStack<int> v(2,5));
}

TEST(MultiStack, can_create_MultiStack)
{
	ASSERT_NO_THROW(MultiStack<int> v);
}

TEST(MultiStack, throws_when_create_MultiStack_with_negative_CeilsCountOrStackCount)
{
	ASSERT_ANY_THROW(MultiStack<int> v(-5,-2));
}

TEST(MultiStack, Can_copy_MultiStack)
{
	MultiStack<int>q(2,4);
	ASSERT_NO_THROW(MultiStack<int>w(q));
}
TEST(MultiStack, IsFull)
{
	MultiStack<int>q(1,1);
	int m = 2;
	q.push(m,0);
	EXPECT_EQ(q.is_full(), 1);
}

TEST(MultiStack, IsEmpty)
{
	MultiStack<int>q(1,1);
	int m = 2;
	q.push(m,0);
	q.pop(0);
	EXPECT_EQ(q.is_empty(), 1);
}

TEST(MultiStack, can_work_with_two_stacks)
{
	MultiStack<int> v(2,3);
	int m = 3;
	v.push(m, 0);
	v.push(m, 0);
	v.push(m, 0);
	v.push(m, 1);
	v.push(m, 1);
	EXPECT_EQ((v.pop(0) + v.pop(1)), 6);
}

TEST(MultiStack, push_and_pop)
{
	MultiStack<int> v(4,4);
	int a=1, b=2, c=3, d=4;
	v.push(a, 0);
	v.push(b, 1);
	v.push(c, 2);
	v.push(d, 3);
	int sum = 0;
	for (int i = 0; i < 4; i++)sum += v.pop(i);
	EXPECT_EQ(sum, 10);
}

//TEST(Multistack,pp){}



