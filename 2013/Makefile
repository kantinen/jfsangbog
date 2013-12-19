BASENAME  = sanghaefte
BOOKNAME  = booklet
FILENAME  = sanghaefte13
OUTDIR    = $(CURDIR)/output
OUTFILE   = $(OUTDIR)/$(FILENAME).pdf

COMPILE   = pdflatex -output-directory=output -file-line-error \
            -jobname $(FILENAME) $(BASENAME)
COMPILE2  = pdflatex -output-directory=output -file-line-error \
            -jobname $(BOOKNAME) $(BOOKNAME)

default: compile
compile:
	@mkdir -p $(OUTDIR)
	$(COMPILE) && $(COMPILE)
	$(COMPILE2) && $(COMPILE2)

bibtex: compile
	cd $(OUTDIR)
	bibtex $(FILENAME).aux
	cd $(CURDIR)

print:
	cat $(OUTFILE) | ssh ask.diku.dk lpr -P m1b

clean:
	rm -r $(OUTDIR)

