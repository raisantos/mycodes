;1º Questão - Fatorial

(defun factorial (num)
   (cond ((zerop num) 1)
      (t ( * num (factorial (- num 1))))
   )
)
(setq n 6)
(format t "~% Factorial ~d is: ~d" n (factorial n))

;------------------------------------------------------------------------------------------------------------------------------
;2º Questão  Sequência Fibonacci
(defun fibonacci (num)
    (cond ((= num 1) 0)
        ((= num 2) 1)	
            (t (+ (fibonacci(- num 1)) (fibonacci (- num 2))))
    )
)
(setq n 5)
(format t "~% The ~d number in the Fibonacci Sequence is: ~d" n (fibonacci n))

;-----------------------------------------------------------------------------------------------------------
;3º Questão  - União 
((defun uniao (l1 l2)
    (setq luniao (copy-seq l2))
    (mapcar 
        (lambda (x y) 
        (cond ((not(position x l2)) (pushnew x luniao))))
        l1 l2)
    (sort luniao '<)
    (return-from uniao luniao)
)

(setq a (list 1 2 3 ))
(setq b (list 3 4 5 1))
(write (uniao a b))

;------------------------------------------------------------------------------------------------------------------------------
;4º Questão - Intersecção 	
(defun intersecao (l1 l2)
    (setq lintersecao (list))
    (mapcar 
        (lambda (x y) 
        (cond ((position x l2) (pushnew x lintersecao))))
        l1 l2)
    (sort lintersecao '<)
    (return-from intersecao lintersecao)
)

(setq a (list 1 2 3 ))
(setq b (list 3 4 5 1))
(write (intersecao a b))

;------------------------------------------------------------------------------------------------------------------------------
;5º Questão - RodarEsquerda

defun rodarEsquerda ( num lista)
	(dotimes (i num)
	    (setq ultimap (- (length lista) 1))
	    (setq anterior(elt lista ultimap))
	    (setq atual nil)
	    (loop for j from 1 to ultimap
		    do
		       	   (setq posicao (- ultimap j))
			    (setq atual (elt lista posicao))
			    (setf (elt lista posicao) anterior)
			    (setq anterior atual)
        )
         (setf (elt lista ultimap) atual)
    )
    (return-from rodarEsquerda lista)
)

(setq a (list 1 2 3))
(write (rodarEsquerda 2 a ))
;-----------------------------------------------------------------------------------------------------------
;6º Questão – RodarDireita

(defun rodarDireita( num lista)
	(dotimes (i num)
	    (setq ultimap (- (length lista) 1))
	    (setq primeirap 0)
	    (setq anterior(elt lista primeirap))
	    (setq atual nil)
	    (loop for j from 1 to ultimap
		    do
		        (setq posicao j)
			    (setq atual (elt lista posicao))
			    (setf (elt lista posicao) anterior)
			    (setq anterior atual)
        )
         (setf (elt lista primeirap) atual)
    )
    (return-from rodarDireita lista)
)

(setq a (list 1 2 3))
(write (rodarDireita 2 a ))

;--------------------------------------------------------------------------------------------------------------------------------
;7º Questão –  vetorSeleção

(defun selecao (lista listaindice)
        (setq ultimap ( - (length listaindice) 1))
        (setq listaselecao (list))
	    (loop for j from 0 to ultimap
		    do
		        (setq posicao (- ultimap j))
			    (setq listaselecao (cons (elt lista (elt listaindice posicao)) listaselecao))
        )
        (return-from selecao listaselecao)
)

(setq l (list 3 22 15 17 18))
(setq posicao (list 0 0 1 1 2 2 3 3 4 4))
(write (selecao l posicao))

;--------------------------------------------------------------------------------------------------------------------------------
;8º Questão Primo 

(defun primo (num)
        (setq count 0)
	    (loop for i from 2 to (- num 1)
		    do
		        (if ( = (mod num i) 0)
		            (setq count (+ count 1))
		        )
        )
        (return-from primo (= count 0))
)
(setq num 5)
(write (primo num)) 

;--------------------------------------------------------------------------------------------------------------------------------
;Questão 9 - quadrado perfeito
(defun perfeito (n)
  (= n (loop for i from 1 below n when (= 0 (mod n i)) sum i)))

;--------------------------------------------------------------------------------------------------------------------------------
;Questão 10 - conjunto das partes
(defun conjunt (list)
	(if (null list) '(nil)
	(let * (( a (car list))
		(d (cdr list))
		(s (conjunt d))
		(v (mapcar (lambda (x) (cons a x )) s )))
		(append s v ))))
