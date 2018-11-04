public class Solution {
    public static ListNode partition(ListNode head, int x) {
        ListNode left = new ListNode(0), left_head = left;
        ListNode right = new ListNode(0), right_head = right;
        while(head != null){
            if(head.val < x){
                left.next = head;
                left = left.next;
            }
            else{
                right.next = head;
                right = right.next;
            }
            head = head.next;
        }
        right.next = null;
        left.next = right_head.next;
        return left_head.next;
    }

    public static void main(String[] args){
	ListNode a = new ListNode(1);
	a.next = new ListNode(4);
	a.next.next = new ListNode(3);
	a.next.next.next = new ListNode(2);
	a.next.next.next.next = new ListNode(5);
	a.next.next.next.next.next = new ListNode(2);
	ListNode res = partition(a, 3);
	System.out.print("[");
	while(res != null){
	    System.out.print(res.val + " ");
	    res = res.next;
	}
	System.out.println("]");
    }
}