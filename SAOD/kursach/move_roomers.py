# вселение и выселение постояльцев

class Move_roomer():
    def __init__(self, pasport, number, date_in, date_out):
        self.pasport = pasport
        self.number = number
        self.date_in = date_in
        self.date_out = date_out

class Element_list:
    def __init__(self, item, head=None):
        self.item = item

        self.next = None
        self.previous = None
        self.head = (self if (head == None) else head)

    def add(self, item):
        next = self.head
        while (next.next != None):
            next = next.next

        next.next = Element_list(item, self.head)
        next.next.previous = next.next
        return next.next

    def get_item(self):
        return self.item

    def get_head(self):
        return self.head

    def get_all(self):
        result = []
        head = self.head
        while (head != None):
            result.append(head.item)
            head = head.next

        return result

    def get_current_item(self, id):
        head = self.head
        for _ in range(id):
            head = head.next

        return head

    def delete_element(self, id):
        if (id < 0 or id > (self.get_length() - 1)):
            return False

        if id == 0:
            self.head = self.head.next
            return True

        elem_curr = self.head
        elem_prev = None
        elem_next = None
        for i in range(id):
            elem_prev = elem_curr
            elem_curr = elem_curr.next
            elem_next = elem_curr.next

        elem_prev.next = elem_next
        elem_next.previous = elem_prev

        return True

    def get_length(self):
        head = self.head
        count = 0
        while (head != None):
            head = head.next
            count += 1

        return count

################################################################################

    def search_by_pasport(self, pasport):
        head = self.head
        count = 0
        while (head != None):
            if self.item.pasport == pasport:
                return count

            head = head.next
            count += 1

        return None

    def search_by_number(self, number):
        head = self.head
        result = []
        while (head != None):
            if head.item.number == number:
                result.append(head.item)

            head = head.next

        return result
