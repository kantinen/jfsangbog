BASENAME  = sanghaefte
BOOKNAME  = booklet
FILENAME  = sanghaefte17-en
OUTDIR    = $(CURDIR)/output
OUTFILE   = $(OUTDIR)/$(FILENAME).pdf

COMPILE   = pdflatex -shell-escape -output-directory=output -file-line-error \
            -jobname $(FILENAME) $(BASENAME)
COMPILE2  = pdflatex -output-directory=output -file-line-error \
            -jobname $(BOOKNAME) $(BOOKNAME)

default: compile
compile:
	@mkdir -p $(OUTDIR)
	$(COMPILE) && $(COMPILE)
	$(COMPILE2) && $(COMPILE2)

clean:
	rm -r $(OUTDIR)

