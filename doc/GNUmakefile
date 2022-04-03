HOWTOS_TOP = ..

# Note: the HTML and PDF main files differ, to accomodate their different
# structure (autonomous yet interlinked HTML pages vs a single standalone PDF).


# For HTML; includes "overview":
DOC_BASE_NAME := Ceylan-HOWTOs-overview-english

OVERALL_DOCUMENT_SOURCE := $(DOC_BASE_NAME).rst


CURRENT_HOWTOS_HTML := $(DOC_BASE_NAME).html

HTML_TARGET = $(CURRENT_HOWTOS_HTML)


# No "overview" wanted here:
PDF_TARGET := Ceylan-HOWTOs-english.pdf


DOC_GENERATED_FILES := $(HOWTO_HTML_FILES) $(HTML_TARGET) $(PDF_TARGET)


# Only the source files of actual HOWTOs:
HOWTO_TEMPLATES = $(filter-out $(OTHER_TEMPLATES),$(wildcard *.rst.template))

OTHER_TEMPLATES = $(SYMLINKS) $(OVERALL_DOCUMENTS)

# Just introduced for convenience:
SYMLINKS = Ceylan-HOWTOs-top-level-html.rst.template \
		   Ceylan-HOWTOs-top-level-pdf.rst.template

# For the main HTML/PDF documents of interest:
OVERALL_DOCUMENTS = Ceylan-HOWTOs-overview-english.rst.template         \
					Ceylan-HOWTOs-english.rst.template

HOWTO_RST_FILES = $(patsubst %.rst.template,%.rst,$(HOWTO_TEMPLATES))
HOWTO_HTML_FILES = $(patsubst %.rst.template,%.html,$(HOWTO_TEMPLATES))


PROJECT_CSS := pygments-default.css,howtos.css

PROJECT_ICON := howtos-icon.png


# Read from the user's environment:
GITHUB_PAGES_BASE := $(shell basename "$(HOWTOS_WEB_MIRROR_BRANCH)")



.PHONY: doc all full-doc html pdf clone-mirror                      \
		export-doc export-to-official export-to-mirror              \
		clean clean-doc clean-links info info-howtos info-web


# Default do-nothing target:
all:
	@echo "  Run 'make doc' to generate the HOWTOs documentation."


doc: html pdf

doc:


# The HTML version just links to the HOWTOs pages, the PDF includes them:

html: $(HOWTO_HTML_FILES) $(HTML_TARGET)
	@echo "  The HTML content for HOWTOs is available at: file://$$(pwd)/Ceylan-HOWTOs-overview-english.html"


pdf: $(HOWTO_RST_FILES) $(PDF_TARGET)


# This link does not need to be in version control:
create-links:
	@/bin/ln -sf $(CURRENT_HOWTOS_HTML) index.html



export-doc: clean-doc full-doc export-to-official export-doc-to-mirror


# Drawback: scp will not preserve symlinks, it will duplicate files instead
# (which may be useful though, for example for MathJax).
#
# rsync would not, but requires a different source layout (copies a full tree,
# not a set of files), so currently not used:
# rsync -avze "ssh $(SP)" $(SOME_WEB_TREE) $(WEB_SRV):$(WEB_ROOT)/Howtos/
#
export-to-official: check-mathjax clean-doc create-links doc
	@echo "   Exporting HOWTOs documentation to official website ($(WEB_SRV))"
	@/bin/scp $(SP) -r $(WEB_CONTENT) $(WEB_SRV):$(WEB_ROOT)/Howtos/


# H option for cp so that a local MathJax is copied in target branch:
export-doc-to-mirror: check-mathjax clean-doc create-links doc
	@echo "   Exporting HOWTOs documentation to mirror website in $(HOWTOS_WEB_MIRROR_BRANCH)"
	@/bin/cp -rfH $(WEB_CONTENT) $(HOWTOS_WEB_MIRROR_BRANCH) && cd $(HOWTOS_WEB_MIRROR_BRANCH) && git add . && git merge -s ours && git commit -m "HOWTOs doc updated." && git push && git pull --ff-only



info: info-howtos info-web


info-howtos:
	@echo "HOWTO_TEMPLATES = $(HOWTO_TEMPLATES)"
	@echo "HOWTO_RST_FILES = $(HOWTO_RST_FILES)"
	@echo "HOWTO_HTML_FILES = $(HOWTO_HTML_FILES)"
	@echo "DOC_GENERATED_FILES = $(DOC_GENERATED_FILES)"


info-web:
	@echo "HTML_TARGET = $(HTML_TARGET)"
	@echo "SP = $(SP)"
	@echo "WEB_CONTENT = $(WEB_CONTENT)"
	@echo "WEB_SRV = $(WEB_SRV)"
	@echo "WEB_ROOT = $(WEB_ROOT)"


DOCUTILS_TOP = .

# For MYRIAD_TOP:
include $(HOWTOS_TOP)/GNUmakesettings.inc