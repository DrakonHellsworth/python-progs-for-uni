import os
import sys
import tempfile
from glob import glob
from PyPDF2 import PdfMerger
from reportlab.lib import colors
from reportlab.lib.pagesizes import letter
from reportlab.lib.styles import getSampleStyleSheet, ParagraphStyle
from reportlab.platypus import (
    SimpleDocTemplate, Paragraph, Spacer, PageBreak, Table, TableStyle
)
from pygments import lex
from pygments.lexers import CLexer
from pygments.token import Token

# Check for C files first
c_files = sorted(glob("*.c"), key=os.path.getmtime)
if not c_files:
    print("Error: No .c files found in current directory!")
    sys.exit(1)

# Create outputs directory
os.makedirs("outputs", exist_ok=True)

def get_program_name(file_path):
    """Extract program name from first comment line"""
    try:
        with open(file_path, "r", encoding="utf-8") as f:
            for line in f:
                stripped = line.strip()
                if stripped.startswith("//"):
                    return stripped[2:].strip()
                elif stripped.startswith("/*"):
                    end_idx = stripped.find("*/")
                    return stripped[2:end_idx].strip() if end_idx != -1 else stripped[2:].strip()
    except Exception as e:
        print(f"Error reading {file_path}: {str(e)}")
    return os.path.basename(file_path)

def highlight_code(code):
    """Convert C code to formatted text with syntax highlighting"""
    try:
        lexer = CLexer()
        tokens = lex(code, lexer)
        formatted = []
        for token_type, value in tokens:
            if token_type in Token.Keyword:
                formatted.append(f'<font color="blue"><b>{value}</b></font>')
            elif token_type in Token.String:
                formatted.append(f'<font color="green">{value}</font>')
            elif token_type in Token.Comment:
                formatted.append(f'<font color="gray"><i>{value}</i></font>')
            else:
                formatted.append(value)
        result = "".join(formatted).replace("\n", "<br/>")
        return result if result.strip() else "<pre>Empty Code Block</pre>"
    except Exception as e:
        print(f"Syntax highlighting error: {str(e)}")
        return "<pre>Error in Code Formatting</pre>"

# Collect program data
programs = []
for i, c_file in enumerate(c_files, start=1):
    try:
        with open(c_file, "r", encoding="utf-8") as f:
            code_content = f.read().strip()
        if not code_content:
            print(f"Skipping {c_file} as it's empty.")
            continue
        programs.append({"number": i, "name": get_program_name(c_file), "code": code_content})
    except Exception as e:
        print(f"Skipping {c_file} due to error: {str(e)}")

if not programs:
    print("No valid programs processed!")
    sys.exit(1)

# Generate content PDF
content_pdf = tempfile.NamedTemporaryFile(delete=False, suffix=".pdf")
try:
    content_doc = SimpleDocTemplate(content_pdf.name, pagesize=letter, leftMargin=40, rightMargin=40)
    styles = getSampleStyleSheet()
    content_flowables = []
    code_style = ParagraphStyle("CodeStyle", fontName="Courier", fontSize=10, leading=12)
    page_numbers = []
    current_page = 2

    for idx, prog in enumerate(programs):
        if idx > 0:
            content_flowables.append(PageBreak())
        content_flowables.append(Paragraph(f"Program {prog['number']}: {prog['name']}",
                                           ParagraphStyle("Heading1", parent=styles["Heading1"], fontSize=14, spaceAfter=12)))
        content_flowables.append(Paragraph(highlight_code(prog["code"]), code_style))
        content_flowables.append(Spacer(1, 12))
        page_numbers.append(current_page)
        current_page += 1

    content_doc.build(content_flowables)
except Exception as e:
    print(f"Error generating content PDF: {str(e)}")
    sys.exit(1)

# Generate index PDF
index_pdf = tempfile.NamedTemporaryFile(delete=False, suffix=".pdf")
try:
    index_doc = SimpleDocTemplate(index_pdf.name, pagesize=letter)
    index_data = [["Serial No.", "Program Name", "Page No."]]
    for idx, prog in enumerate(programs):
        index_data.append([str(prog['number']), prog['name'], str(page_numbers[idx]) if idx < len(page_numbers) else "N/A"])
    index_table = Table(index_data)
    index_table.setStyle(TableStyle([
        ("BACKGROUND", (0,0), (-1,0), colors.HexColor("#4CAF50")),
        ("TEXTCOLOR", (0,0), (-1,0), colors.whitesmoke),
        ("ALIGN", (0,0), (-1,-1), "CENTER"),
        ("FONTNAME", (0,0), (-1,0), "Helvetica-Bold"),
        ("FONTSIZE", (0,0), (-1,0), 12),
        ("BOTTOMPADDING", (0,0), (-1,0), 12),
        ("BACKGROUND", (0,1), (-1,-1), colors.HexColor("#F3F3F3")),
        ("GRID", (0,0), (-1,-1), 1, colors.black),
    ]))
    index_doc.build([Paragraph("<u><b>Index</b></u>", ParagraphStyle("Title", parent=styles["Title"], fontSize=18, spaceAfter=20, alignment=1)), index_table])
except Exception as e:
    print(f"Error generating index PDF: {str(e)}")
    sys.exit(1)

# Merge PDFs
try:
    merger = PdfMerger()
    merger.append(index_pdf.name)
    merger.append(content_pdf.name)
    merger.write("programs_documentation.pdf")
    merger.close()
except Exception as e:
    print(f"Error merging PDFs: {str(e)}")
    sys.exit(1)
finally:
    os.unlink(index_pdf.name)
    os.unlink(content_pdf.name)

print("\nPDF generated successfully: programs_documentation.pdf")
