# Title: Cyrillic characters not rendering correctly in Draw.io XML import

*Description:*

When importing or opening the DFD XML diagram in Draw.io (diagrams.net), Cyrillic (Bulgarian)
text may not display properly or show garbled characters.

This typically happens if the file was saved using an incorrect text encoding (such as ANSI or Windows-1251) instead of UTF-8.

*Solution:*

Ensure the file is saved with UTF-8 encoding.

Alternatively, use the "Edit Diagram" feature in Draw.io and paste the raw XML code directly
to preserve the correct UTF-8 encoding automatically.
