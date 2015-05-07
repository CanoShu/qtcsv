#include "testreader.h"

#include <QDir>

#include "reader.h"
#include "stringdata.h"
#include "variantdata.h"

TestReader::TestReader()
{
}

void TestReader::testReadFileWithCommas()
{
    const QString path = getPathToFileTestComma();
    QList<QStringList> data = QtCSV::Reader::readToList(path);

    QVERIFY2(false == data.isEmpty(), "Failed to read file content");
    QVERIFY2(5 == data.size(), "Wrong number of rows");

    QStringList expectedFirstRow;
    expectedFirstRow << "one" << "two" << "three";

    QStringList expectedSecondRow;
    expectedSecondRow << "one_element";

    QStringList expectedThirdRow;
    expectedThirdRow << "1" << "2" << "3";

    QStringList expectedFourthRow;
    expectedFourthRow << "";

    QStringList expectedFifthRow;
    expectedFifthRow << "3.14";

    QVERIFY2(expectedFirstRow == data.at(0), "Wrong first row");
    QVERIFY2(expectedSecondRow == data.at(1), "Wrong second row");
    QVERIFY2(expectedThirdRow == data.at(2), "Wrong third row");
    QVERIFY2(expectedFourthRow == data.at(3), "Wrong fourth row");
    QVERIFY2(expectedFifthRow == data.at(4), "Wrong fifth row");
}

void TestReader::testReadFileWithCommasToStringData()
{
    const QString path = getPathToFileTestComma();
    QtCSV::StringData strData;
    bool readResult = QtCSV::Reader::readToData(path, strData);
    QVERIFY2(true == readResult, "Failed to read file content");

    QVERIFY2(false == strData.isEmpty(), "StringData is empty");
    QVERIFY2(5 == strData.getNumberOfRows(), "Wrong number of rows");

    QStringList expectedFirstRow;
    expectedFirstRow << "one" << "two" << "three";

    QStringList expectedSecondRow;
    expectedSecondRow << "one_element";

    QStringList expectedThirdRow;
    expectedThirdRow << "1" << "2" << "3";

    QStringList expectedFourthRow;
    expectedFourthRow << "";

    QStringList expectedFifthRow;
    expectedFifthRow << "3.14";

    QVERIFY2(expectedFirstRow == strData.getRowValues(0), "Wrong first row");
    QVERIFY2(expectedSecondRow == strData.getRowValues(1), "Wrong second row");
    QVERIFY2(expectedThirdRow == strData.getRowValues(2), "Wrong third row");
    QVERIFY2(expectedFourthRow == strData.getRowValues(3), "Wrong fourth row");
    QVERIFY2(expectedFifthRow == strData.getRowValues(4), "Wrong fifth row");
}

void TestReader::testReadFileWithCommasToVariantData()
{
    const QString path = getPathToFileTestComma();
    QtCSV::VariantData varData;
    bool readResult = QtCSV::Reader::readToData(path, varData);
    QVERIFY2(true == readResult, "Failed to read file content");

    QVERIFY2(false == varData.isEmpty(), "StringData is empty");
    QVERIFY2(5 == varData.getNumberOfRows(), "Wrong number of rows");

    QStringList expectedFirstRow;
    expectedFirstRow << "one" << "two" << "three";

    QStringList expectedSecondRow;
    expectedSecondRow << "one_element";

    QStringList expectedThirdRow;
    expectedThirdRow << "1" << "2" << "3";

    QStringList expectedFourthRow;
    expectedFourthRow << "";

    QStringList expectedFifthRow;
    expectedFifthRow << "3.14";

    QVERIFY2(expectedFirstRow == varData.getRowValues(0), "Wrong first row");
    QVERIFY2(expectedSecondRow == varData.getRowValues(1), "Wrong second row");
    QVERIFY2(expectedThirdRow == varData.getRowValues(2), "Wrong third row");
    QVERIFY2(expectedFourthRow == varData.getRowValues(3), "Wrong fourth row");
    QVERIFY2(expectedFifthRow == varData.getRowValues(4), "Wrong fifth row");
}

void TestReader::testReadFileWithSemicolons()
{
    const QString path = getPathToFileTestSemicolon();
    QList<QStringList> data = QtCSV::Reader::readToList(path, ";");

    QVERIFY2(false == data.isEmpty(), "Failed to read file content");
    QVERIFY2(2 == data.size(), "Wrong number of rows");

    QStringList expectedFirstRow;
    expectedFirstRow << "1" << "2" << "3";

    QStringList expectedSecondRow;
    expectedSecondRow << "j" << "io" << "pp";

    QVERIFY2(expectedFirstRow == data.at(0), "Wrong first row");
    QVERIFY2(expectedSecondRow == data.at(1), "Wrong second row");
}

void TestReader::testReadFileWithSemicolonsToStringData()
{
    const QString path = getPathToFileTestSemicolon();
    QtCSV::StringData strData;
    bool readResult = QtCSV::Reader::readToData(path, strData, ";");
    QVERIFY2(true == readResult, "Failed to read file content");

    QVERIFY2(false == strData.isEmpty(), "Failed to read file content");
    QVERIFY2(2 == strData.getNumberOfRows(), "Wrong number of rows");

    QStringList expectedFirstRow;
    expectedFirstRow << "1" << "2" << "3";

    QStringList expectedSecondRow;
    expectedSecondRow << "j" << "io" << "pp";

    QVERIFY2(expectedFirstRow == strData.getRowValues(0), "Wrong first row");
    QVERIFY2(expectedSecondRow == strData.getRowValues(1), "Wrong second row");
}

void TestReader::testReadFileWithSemicolonsToVariantData()
{
    const QString path = getPathToFileTestSemicolon();
    QtCSV::VariantData varData;
    bool readResult = QtCSV::Reader::readToData(path, varData, ";");
    QVERIFY2(true == readResult, "Failed to read file content");

    QVERIFY2(false == varData.isEmpty(), "Failed to read file content");
    QVERIFY2(2 == varData.getNumberOfRows(), "Wrong number of rows");

    QStringList expectedFirstRow;
    expectedFirstRow << "1" << "2" << "3";

    QStringList expectedSecondRow;
    expectedSecondRow << "j" << "io" << "pp";

    QVERIFY2(expectedFirstRow == varData.getRowValues(0), "Wrong first row");
    QVERIFY2(expectedSecondRow == varData.getRowValues(1), "Wrong second row");
}

QString TestReader::getPathToFolderWithTestFiles() const
{
    return QDir::currentPath() + "/data/";
}

QString TestReader::getPathToFileTestComma() const
{
    return getPathToFolderWithTestFiles() + "test-comma.csv";
}

QString TestReader::getPathToFileTestSemicolon() const
{
    return getPathToFolderWithTestFiles() + "test-semicolon.csv";
}