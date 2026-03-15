#>
 extern char* calc(void);
 extern char* result;
<#


(import
  (chicken foreign)    
  (chicken base)
  (chicken platform)
  (scheme)
  (srfi 196)
  (srfi 130)
  (srfi 196)
  (srfi 158)  
  (srfi 69)
  (srfi 13)
  (medea)    
  (chicken process-context) srfi-18)
;;csc -embedded CscCalcC.c CscCalc.scm -L"-lgmp" -L "-lmpfr" -o CscCalc


(define-foreign-variable result  c-string "result")
;(define calc
;  (foreign-lambda* (c-pointer char) () "calc();"))

(define calc
  (foreign-lambda c-string* "calc"))


; (define get-c-string
;   (foreign-lambda c-string* "generate_string"))
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


(define (start)
(display (calc))
; (thread-sleep! .1)
;(display result)
(newline)
;(display (grid->string grid2))
; (let loop ()
;   (if (not (= (string-length wsResponse ) 0))
;     (begin 
;       ;(runthis grid2)      
;       (processString wsResponse)
;       ;(print wsResponse)
      
;       ;
;      (clearResponse)
;     )
;   )
;   (thread-sleep! .001)
; (loop))
)


(return-to-host)


