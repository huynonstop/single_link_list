// Lưu ý: Các ghi chú chỉ là gợi ý, SV có thể làm theo cách riêng
#include "SinglyLinkedList.h"
#include <iostream>
using namespace std;

// 01. Hàm so sánh 2 biến kiểu cấu trúc cho trước
// Đầu vào: biến cấu trúc (info1) và biến cấu trúc (info2)
// Đầu ra:	0 (bằng nhau), -1 (info1 nhỏ hơn info2), 1 (info1 lớn hơn info2)
int CompareData(Data info1, Data info2)
{
	if (info1.x > info2.x) return 1;
	else if (info1.x == info2.x) return 0;
	else return -1;
}

// 02. Hàm khởi tạo DSLK (rỗng)
// Đầu vào:	tham chiếu đến DSLK cần khởi tạo (l)
// Đầu ra:	Không có
void InitList(List& l)
{
	// Khởi tạo cho DSLK rỗng nghĩa là pHead và pTail đều bằng NULL
	l.pHead = NULL;
	l.pTail = NULL;
}

// 03. Hàm kiểm tra DSLK cho trước có phải là DSLK rỗng hay không?
// Đầu vào:	DSLK cần kiểm tra (l)
// Đầu ra:	DSLK rỗng hay không (true/false)
bool IsEmptyList(List l)
{
	// Nếu pHead bằng NULL thì DSLK rỗng
	if (l.pHead == NULL) return true;
	// Ngược lại DSLK không rỗng
	return false;
}

// 04. Hàm in DSLK cho trước
// Đầu vào: DSLK cần in (l) kèm theo chuỗi thông báo (str)
// Đầu ra:	Không có
void PrintList(List l, char* str)
{
	if (l.pHead == NULL)
	{
		return;
	}
	printf("%s\n", str);
	// Xuất phát từ đầu DSLK

	// Trong khi chưa kết thúc DSLK (nút đang xét khác NULL)
		// thì xuất thông tin nút đó ra
		// và đi tới nút kế tiếp
	for (Node* p = l.pHead; p != NULL; p=p->pNext)
	{
		printf("%d\n", p->info.x);
	}
}

// 05. Hàm tạo một nút mới với dữ liệu cho trước
// Đầu vào:	Dữ liệu của nút (info)
// Đầu ra:	Con trỏ đến nút đó (trả về NULL nếu không tạo được)
Node* CreateNode(Data info)
{
	// Tạo một nút mới
	Node* newNODE=new Node;
	// Nếu tạo được nút mới (khác NULL)
		// thì gán thông tin cho nút đó
		// và không cho nút đó trỏ đến đâu cả (nút kế bằng NULL)
	if (newNODE != NULL)
	{
		newNODE->info = info;
		newNODE->pNext = NULL;
	}
	// Trả về con trỏ đến nút tạo được
	// Nếu không tạo được thì con trỏ bằng NULL (đúng yêu cầu đề bài)
	return newNODE;
}

// 06. Hàm tìm nút đầu tiên trong DSLK cho trước có dữ liệu cho trước
// Đầu vào:	DSLK (l), dữ liệu của nút cần tìm (info)
// Đầu ra:	Con trỏ đến nút tìm được (trả về NULL nếu không tìm được)
Node* GetNodePointer(List l, Data info)
{
	// Xuất phát từ đầu DSLK
	Node* p = l.pHead;
	// Trong khi chưa kết thúc DSLK (nút đang xét khác NULL)
	// và dữ liệu của nút đang xét khác dữ liệu cho trước
		// thì đi tới nút kế tiếp
	while (p != NULL&&(CompareData(p->info, info) != 0))
	{
		p = p->pNext;
	}
	// Trả về con trỏ đến nút tìm được
	// Nếu không tìm được thì nút đó sẽ là NULL do kết thúc DSLK
	return p;
}

// 07. Hàm tìm nút có chỉ số (bắt đầu từ 0) cho trước
// Đầu vào:	DSLK (l), chỉ số của nút cần lấy (index)
// Đầu ra:	Con trỏ đến nút tìm được (trả về NULL nếu không tìm được)
Node* GetNodePointer(List l, int index)
{
	// Chỉ số đầu tiên bằng 0 (đầu DSLK)
	int i = 0;
	// Xuất phát từ đầu DSLK
	Node* p = l.pHead;
	// Trong khi chưa kết thúc DSLK (nút hiện tại khác NULL)
	// và chỉ số hiện tại vẫn chưa bằng chỉ số cần
		// thì đi tới nút kế tiếp
		// và tăng chỉ số hiện tại lên 1 đơn vị
	while (p != NULL && (i!=index))
	{
		p = p->pNext;
		i++;
	}
	// Trả về con trỏ đến nút tìm được
	// Nếu không tìm được thì nút đó sẽ là NULL do kết thúc DSLK
	return p;
}

// 08. Hàm xác định vị trí của một nút cho trước trong DSLK cho trước
// Đầu vào:	DSLK (l), con trỏ đến nút cần xác định vị trí (pNode)
// Đầu ra:	Thứ tự của nút cho trước (trả về -1 nếu nút này không có trong DSLK)
int GetNodeIndex(List l, Node* pNode)
{
	// Xuất phát từ đầu DSLK
	Node* p = l.pHead;
	// Vị trí hiện tại bằng 0
	int i = 0;
	// Nếu DSLK rỗng thì dừng lại và trả về -1
	// do không thấy nút này trong DSLK
	if (IsEmptyList(l) == true) return -1;
	// Trong khi chưa kết thúc DSLK (nút đang xét khác NULL)
	// và nút đang xét vẫn khác nút cho trước
		// thì tăng vị trí hiện tại lên
		// và đi tới nút kế tiếp
	while (p != NULL && p != pNode)
	{
		p = p->pNext;
		i++;
	}
	// Khi kết thúc, nếu con trỏ đến nút hiện tại bằng con trỏ đến nút cho trước
	// thì trả về vị trí hiện tại đó
	// ngược lại trả về -1 (không tìm thấy)
	if (p == NULL) return -1;
	return i;
}

// 09. Hàm xác định con trỏ đến nút đứng trước của một nút cho trước trong DSLK
// Đầu vào:	DSLK (l), con trỏ đến nút cho trước (pNode)
// Đầu ra:	Con trỏ đến nút tìm được (trả về NULL nếu không tìm được)
Node* GetPreviousNodePointer(List l, Node* pNode)
{
	// Nút trước đó đầu tiên là nút đầu DSLK
	Node* p = l.pHead;
	if (p == pNode) return NULL;
	// Trong khi chưa kết thúc DSLK (nút đang xét khác NULL)
	// và nút sau nút đó không phải nút cho trước
		// thì đi đến nút kế tiếp
	while (p != NULL && p->pNext != pNode)
	{
		p = p->pNext;
	}
	// Trả về con trỏ đến nút trước nút cho trước nếu tìm được
	// Nếu không tìm được thì nút đó vẫn là NULL (đúng yêu cầu đề bài)
	return p;
}

// 10. Hàm chèn một nút cho trước vào đầu DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddHead(List& l, Node* pNewNode)
{
	// Nếu DSLK rỗng
		// thì đây là nút đầu tiên của DSLK
		// nghĩa là pHead và pTail đề trỏ đến nút đầu tiên này
	if (IsEmptyList(l) == true)
	{
		l.pHead = pNewNode;
		l.pTail = pNewNode;
	}
	// Ngược lại (DSLK không rỗng)
		// thì nút mới trỏ tới nút đầu DSLK
		// rồi pHead trỏ tới nút mới
	else
	{
		pNewNode->pNext = l.pHead;
		l.pHead = pNewNode;
	}
}

// 11. Hàm chèn một nút có dữ liệu cho trước vào đầu DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddHead(List& l, Data info)
{
	// Tạo nút mới với dữ liệu cho trước
	Node* pNewNode = CreateNode(info);
	// Nếu tạo được
		// thì gọi hàm đã viết để thêm nút đó vào đầu DSLK
	if (pNewNode != NULL)
	{
		AddHead(l, pNewNode);
	}
	// Trả về nút mới tạo được
	// Nếu không thêm được thì do không tạo được nút mới
	// thì trả về NULL (đúng yêu cầu đề bài)
	return pNewNode;
}

// 12. Hàm chèn một nút cho trước vào cuối DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddTail(List& l, Node* pNewNode)
{
	// Nếu DSLK rỗng
		// thì đây là nút đầu tiên của DSLK
		// nghĩa là pHead và pTail đề trỏ đến nút đầu tiên này
	if (IsEmptyList(l) == true)
	{
		l.pHead = pNewNode;
		l.pTail = pNewNode;
	}
	// Ngược lại (DSLK không rỗng)
		// thì nút cuối DSLK trỏ đến nút mới
		// rồi pTail trỏ tới nút mới
	else
	{
		
		l.pTail->pNext = pNewNode;
		l.pTail = pNewNode;
	}
}

// 13. Hàm chèn một nút có dữ liệu cho trước vào cuối DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddTail(List& l, Data info)
{
	// Tạo nút mới với dữ liệu cho trước
	Node* pNewNode = CreateNode(info);
	// Nếu tạo được
		// thì gọi hàm đã viết để thêm nút đó vào cuối DSLK
	if (pNewNode != NULL)
	{
		AddTail(l, pNewNode);
	}
	// Trả về nút mới tạo được
	// Nếu không thêm được thì do không tạo được nút mới
	// thì trả về NULL (đúng yêu cầu đề bài)
	return pNewNode;
}

// 14. Hàm chèn một nút cho trước vào sau một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddAfter(List& l, Node* q, Node* pNewNode)
{
	// Nếu nút cho trước q khác NULL
	if (q != NULL)
	{
		pNewNode->pNext = q->pNext;
		q->pNext = pNewNode;
	}
		// Lưu ý, sau khi thực hiện xong, nếu nút mới là nút cuối DSLK (nút kế tiếp là NULL)
			// thì cập nhật lại pTail
	if (pNewNode->pNext == NULL)
	{
		l.pTail = pNewNode;
	}
}

// 15. Hàm chèn một nút có dữ liệu cho trước vào sau một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddAfter(List& l, Node* q, Data info)
{
	// Tạo nút mới với dữ liệu cho trước
	Node* pNewNode = CreateNode(info);
	// Nếu tạo được
		// thì gọi hàm đã viết đến để thêm nút đó vào sau nút q cho trước
	if (pNewNode != NULL)
	{
		AddAfter(l, q, pNewNode);
	}
	// Trả về nút mới tạo được
	// Nếu không thêm được thì do không tạo được nút mới
	// thì trả về NULL (đúng yêu cầu đề bài)
	return pNewNode;
}

// 16. Hàm chèn một nút cho trước vào trước một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddBefore(List& l, Node* q, Node* pNewNode)
{
	// Nếu nút q cho trước khác NULL thì mới làm
		// Nếu q cho trước là nút đầu tiên
			// thì gọi hàm thêm vào đầu DSLK
	
		// Ngược lại (q cho trước không phải là nút đầu tiên)
			// thì gọi hàm tìm nút p đứng trước nút q
			// và gọi hàm thêm vào sau nút p cho trước
	if (q != NULL)
	{
		if (q == l.pHead)
		{
			AddHead(l, pNewNode);
		}
		else
		{
			Node* p = GetPreviousNodePointer(l, q);
			AddAfter(l, p, pNewNode);
		}
	}
	
}

// 17. Hàm chèn một nút có dữ liệu cho trước vào trước một nút khác cho trước
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddBefore(List& l, Node* q, Data info)
{
	// Tạo nút mới với dữ liệu cho trước 
	Node* pNewNode = CreateNode(info);
	// Nếu tạo được
		// thì gọi hàm đã viết đến để thêm nút đó vào trước nút q cho trước
	if (pNewNode != NULL)
	{
		AddBefore(l, q, pNewNode);
	}
	// Trả về nút mới tạo được
	// Nếu không thêm được thì do không tạo được nút mới
	// thì trả về NULL (đúng yêu cầu đề bài)
	return pNewNode;
}

// 18. Hàm chèn một nút cho trước sao cho DSLK cho trước vẫn tăng dần
// Đầu vào: Tham chiếu đến DSLK (l), con trỏ đến nút cần chèn (pNewNode)
// Đầu ra:	Không có
void AddAscendingList(List& l, Node* pNewNode)
{
	// Xuất phát từ nút đầu tiên (gọi là p)
	Node* p = l.pHead;
	// sử dụng thêm nút q (ban đầu bằng NULL) để lưu trữ nút trước đó
	Node* q = NULL;
	// do cần phải có nút trước đó để có thể chèn vào sau

	// Trong khi chưa kết thúc DSLK (nút đang xét khác NULL)
	// và dữ liệu của nút p hiện tại vẫn nhỏ hơn nút cần chèn
		// thì dùng nút q để lưu lại nút p hiện tại
		// và cho p đi tới nút tiếp theo
	while (p != NULL&& (p->info.x < pNewNode->info.x))
	{
		q = p;
		p = p->pNext;
	}
	// Nếu q khác NULL nghĩa là tìm được vị trí trong DSLK để chèn
		// thì gọi hàm chèn nút mới vào sau nút q
	// Ngược lại (vẫn là NULL như ban đầu)
		// thì gọi hàm chèn nút mới vào đầu DSLK
	if (q != NULL)
	{
		AddAfter(l, q, pNewNode);
	}
	else
	{
		AddHead(l, pNewNode);
	}
}

// 19. Hàm chèn một nút có dữ liệu cho trước sao cho DSLK cho trước vẫn tăng dần
// Đầu vào: Tham chiếu đến DSLK (l), dữ liệu của nút cần chèn (info)
// Đầu ra:	Con trỏ đến nút được chèn (trả về NULL nếu không chèn được)
Node* AddAscendingList(List& l, Data info)
{
	// Tạo nút mới với dữ liệu cho trước
	Node* pNewNode = CreateNode(info);
	// Nếu tạo được
		// thì gọi hàm đã viết đến để thêm nút đó vào DSLK sao cho DSLK vẫn tăng dần
	if (pNewNode != NULL)
	{
		AddAscendingList(l, pNewNode);
	}
	// Trả về nút mới tạo được
	// Nếu không thêm được thì do không tạo được nút mới
	// thì trả về NULL (đúng yêu cầu đề bài)
	return pNewNode;
}

// 20. Hàm xóa một nút đầu DSLK
// Đầu vào:	Tham chiếu đến DSLK (l)
// Đầu ra:	Con trỏ đến nút bị xóa (nếu có)
Node* RemoveHead(List& l)
{
	// Chuẩn bị sẵn con trỏ đến nút sẽ được xóa
	Node* p = NULL;
	// Nếu DSLK không rỗng nghĩa là có nút đầu để xóa
		// thì ghi nhận lại địa chỉ nút đầu
		// và cập nhật lại pHead
		// Nếu pHead bằng NULL nghĩa là DSLK rỗng thì cập nhật lại pTail
	if (IsEmptyList(l) == false)
	{
		p = l.pHead;
		l.pHead = p->pNext;
		p->pNext = NULL;
		if (l.pHead == NULL)
		{
			l.pTail == NULL;
		}
	}
	// Trả về địa chỉ của nút bị xóa nếu có (nếu không có trả về NULL)
	return p;
}

// 21. Hàm xóa một nút cuối DSLK
// Đầu vào:	Tham chiếu đến DSLK (l)
// Đầu ra:	Con trỏ đến nút bị xóa (nếu có)
Node* RemoveTail(List& l)
{
	// Chuẩn bị sẵn con trỏ đến nút sẽ được xóa
	Node* p = NULL;
	// Nếu DSLK không rỗng nghĩa là có nút cuối để xóa
		// Nếu chỉ có một nút
			// thì gọi hàm xóa nút đầu DSLK
		// Ngược lại (có nhiều hơn 1 nút)
			// thì tìm nút trước nút cuối
			// sau đó gọi hàm xóa nút sau nút tìm được ở trên
	if (IsEmptyList(l) == false)
	{
		if (l.pHead == l.pTail)
		{
			RemoveHead(l);
		}
		else
		{
			for (p = l.pHead; p->pNext != l.pTail; p = p->pNext){}
		/*	l.pTail = p;
			p = l.pTail->pNext;
			l.pTail->pNext = NULL;*/
			p = RemoveAfter(l, p);
		}
	}
	// Trả về địa chỉ của nút bị xóa nếu có (nếu không có trả về NULL)
	return p;
}

// 22. Hàm xóa một nút đứng sau một nút cho trước trong DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), con trỏ đến nút cho trước (q)
// Đầu ra:	Con trỏ đến nút bị xóa (nếu có)
Node* RemoveAfter(List& l, Node* q)
{
	// Chuẩn bị sẵn con trỏ đến nút sẽ được xóa
	Node* p = NULL;
	// Nếu nút đã cho khác NULL
		// và Nếu nút này không phải nút cuối cùng
			// thì ghi nhận lại địa chỉ nút sau nút đã cho (sẽ bị xóa)
			// và nhập nhật lại liên kết
	if (q != NULL)
	{
		if (q != l.pTail)
		{
			p = q->pNext;
			q->pNext = p->pNext;
			p->pNext = NULL;
		}
	}
	// Trả về địa chỉ của nút bị xóa nếu có (nếu không có trả về NULL)
	return p;
}

// 23. Hàm xóa một nút có dữ liệu cho trước trong DSLK
// Đầu vào:	Tham chiếu đến DSLK (l), dữ liệu của nút cần xóa (info)
// Đầu ra:	Con trỏ đến nút bị xóa (nếu có)
Node* RemoveNode(List& l, Data info)
{
	// Chuẩn bị sẵn con trỏ đến nút sẽ được xóa
	Node* p = NULL;
	// Gọi hàm tìm nút có thông tin info cho trước
	p = GetNodePointer(l, info);
	// Nếu tìm được (nghĩa là khác NULL)
		// Nếu đây là nút đầu DSLK
			// thì gọi hàm xóa nút đầu này
		// Ngược lại (không phải nút đầu DSLK)
			// thì gọi hàm tìm nút trước nút này
			// và Nếu tìm được (nghĩa là khác NULL)
				// thì gọi hàm xóa nút sau nút này
	if (p != NULL)
	{
		if (p == l.pHead)
		{
			RemoveHead(l);
		}
		else
		{
			Node* q = GetPreviousNodePointer(l, p);
			if (q != NULL)
			{
				p=RemoveAfter(l, q);
			}
		}
	}
	// Trả về địa chỉ của nút bị xóa nếu có (nếu không có trả về NULL)
	return p;
}

// 24. Hàm hủy toàn bộ DSLK cho trước
// Đầu vào:	Tham chiếu đến DSLK (l)
// Đầu ra:	Không có
void DeleteAll(List& l)
{
	// Cách 1: Gọi hàm xóa nút đầu tiên nhiều lần đến khi DSLK rỗng
	while (IsEmptyList(l) == false)
	{
		delete RemoveHead(l);
	}
	// Cách 2: Chủ động duyệt và hủy từng nút...
	// Sử dụng 1 con trỏ giữ địa chỉ nút sẽ xóa
	// Trong khi DSLK chưa rỗng
		// Giữ địa chỉ nút đầu
		// Cập nhật lại pHead
		// Hủy nút đã giữ
	// Cập nhật lại pTail bằng NULL khi DSLK rỗng
}