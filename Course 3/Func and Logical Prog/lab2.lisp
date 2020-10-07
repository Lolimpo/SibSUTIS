(defun task1(l x)
	(cond
		((null l) nil)
		((or(plusp(car l))(zerop(car l))) (cons (list (car l) x) (task1 (cdr l) x)) )
		(t (cons (car l) (task1 (cdr l) x))) 
	) 
)
(add_num '(1 6 3 0) '*)

(defun task2 (l1 l2)
	(if l1 (cons (car l1) (task2 l2 (cdr l1))) l2)
)
(task2 '(1 2 3 4 5 6) '(a b c))


(defun task3 (lst)
	(if lst 
		(if (eq (car lst) (car (last lst)))
			lst
			(append (list (+ (car lst) (car(last lst))))
					(task3 (cdr (butlast lst)))))
		nil)
)
(task3 '(1 -2 -3 4 5 6 -7 8 9))