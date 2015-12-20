/*****************************************************************************
 * Test cases for libxlsxwriter.
 *
 * Test to compare output against Excel files.
 *
 * Copyright 2014-2015, John McNamara, jmcnamara@cpan.org
 *
 */

#include "xlsxwriter.h"

int main() {

    lxw_workbook  *workbook  = new_workbook("test_shared_strings01.xlsx");
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);
    uint8_t i;
    char c[] = {0x00, 0x00};

    for (i = 1; i < 127; i++) {
        (*c)++;
        if (i != 34) {
            worksheet_write_string(worksheet, i, 0, c, NULL);

        }
    }

    return workbook_close(workbook);
}
