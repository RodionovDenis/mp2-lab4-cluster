#include "queue.h"
#include "gtest.h"

TEST(TQueue, can_create_queue_with_positive_length)
{
  ASSERT_NO_THROW(TQueue<int> q(5));
}
TEST(TQueue, can_not_create_queue_with_negative_size)
{
	ASSERT_ANY_THROW(TQueue<int> q(-1));
}

TEST(TQueue, can_not_create_queue_with_large_size)
{
	ASSERT_ANY_THROW(TQueue<int> q(MaxQueueSize + 1));
}
TEST(TQueue, two_different_queues_have_different_memories)
{
	TQueue<int> q1(2), q2(3);
	EXPECT_NE(&q1, &q2);
}
TEST(TQueue, check_queue_for_empty)
{
	TQueue<int> q1(5);
	EXPECT_EQ(true, q1.IsEmpty());
}
TEST(TQueue, check_queue_for_full)
{
	TQueue<int> q1(5);
	for (int i = 0; i < 5; i++)
		q1.Push(i);
	EXPECT_EQ(true, q1.IsFull());
}
TEST(TQueue, can_assignment_queues)
{
	TQueue<int> q1(5), q2(7);
	q1.Push(1);
	q2 = q1;
	EXPECT_EQ(1, q2.Pop());
}
TEST(TQueue, can_get_size_queue_now)
{
	TQueue<int> q1(5);
	q1.Push(1);
	q1.Push(2);
	EXPECT_EQ(2, q1.GetSize());
}
TEST(TQueue, can_take_element_in_queue_pop_with_corrected_value)
{
	TQueue<int> q1(5);
	for (int i = 0; i < 5; i++)
		q1.Push(i);
	EXPECT_EQ(0, q1.Pop());
}
TEST(TQueue, element_is_delete_on_pop)
{
	TQueue<int> q1(5);
	for (int i = 0; i < 5; i++)
		q1.Push(i);
	int a = q1.Pop();
	EXPECT_EQ(false, q1.IsFull());
}
TEST(TQueue, can_view_last_element_in_queue_without_delete_him)
{
	TQueue<int> q1(5);
	for (int i = 0; i < 5; i++)
		q1.Push(i);
	int a = q1.PopWithoutDelete();
	EXPECT_EQ(true, q1.IsFull());
}
TEST(TQueue,method_pop_without_delete_return_correct_value)
{
	TQueue<int> q1(5);
	for (int i = 0; i < 5; i++)
		q1.Push(i);
	EXPECT_EQ(0, q1.PopWithoutDelete());
}