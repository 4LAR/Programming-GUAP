unsigned char height(Node* p) {
	return p? p -> height: 0;
}

int bfactor(Node* p) {
	return height(p -> right) - height(p -> left);
}

void fixheight(Node* p) {
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p -> height = (hl > hr? hl: hr) + 1;
}

Node* rotateright(Node* p) {
	Node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

Node* rotateleft(Node* q) {
	Node* p = q -> right;
	q -> right = p -> left;
	p -> left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

Node* balance(Node* p) {
	fixheight(p);
	if (bfactor(p) == 2) {
		if (bfactor(p -> right) < 0)
			p->right = rotateright(p -> right);
		return rotateleft(p);
	}
	if (bfactor(p) == -2) {
		if (bfactor(p -> left) > 0)
			p -> left = rotateleft(p -> left);
		return rotateright(p);
	}
	return p; // балансировка не нужна
}
