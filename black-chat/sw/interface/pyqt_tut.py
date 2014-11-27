#!/usr/bin/python
# -*- coding: utf-8 -*-

"""
Simple PyQt4 window example
"""

import sys
from PyQt4 import QtGui


def main():

    app = QtGui.QApplication(sys.argv)

    #w = QtGui.QMainWindow()
    w = QtGui.QWidget()
    w.resize(400, 300)
    w.move(300, 300)
    w.setWindowTitle('BlackChat by Alpaca Security Solutions')
    w.show()

    sys.exit(app.exec_())

if __name__ == '__main__':
    main()