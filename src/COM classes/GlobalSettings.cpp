/**************************************************************************************
 * File name: GlobalSettings.cpp
 *
 * Project: MapWindow Open Source (MapWinGis ActiveX control)
 * Description: Implementation of CGlobalSettings
 *
 **************************************************************************************
 * The contents of this file are subject to the Mozilla Public License Version 1.1
 * (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at http://www.mozilla.org/mpl/
 * See the License for the specific language governing rights and limitations
 * under the License.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 **************************************************************************************
 * Contributor(s):
 * (Open source contributors should list themselves and their modifications here). */

#include "StdAfx.h"
#include "GlobalSettings.h"
#include "BingMapProvider.h"

 // ****************************************************
 //	    get_MinPolygonArea()
 // ****************************************************
STDMETHODIMP CGlobalSettings::get_MinPolygonArea(double* retVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*retVal = m_globalSettings.minPolygonArea;
	return S_OK;
}

// ****************************************************
//	    put_MinPolygonArea()
// ****************************************************
STDMETHODIMP CGlobalSettings::put_MinPolygonArea(const double newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.minPolygonArea = newVal;
	return S_OK;
}

// ****************************************************
//	    get_MinAreaToPerimeterRatio()
// ****************************************************
STDMETHODIMP CGlobalSettings::get_MinAreaToPerimeterRatio(double* retVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*retVal = m_globalSettings.minAreaToPerimeterRatio;
	return S_OK;
}

// ****************************************************
//	    put_MinAreaToPerimeterRatio()
// ****************************************************
STDMETHODIMP CGlobalSettings::put_MinAreaToPerimeterRatio(const double newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.minAreaToPerimeterRatio = newVal;
	return S_OK;
}

// ****************************************************
//	    get_ClipperGcsMultiplicationFactor()
// ****************************************************
STDMETHODIMP CGlobalSettings::get_ClipperGcsMultiplicationFactor(DOUBLE* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = m_globalSettings.clipperGcsMultiplicationFactor;
	return S_OK;
}

// ****************************************************
//	    put_ClipperGcsMultiplicationFactor()
// ****************************************************
STDMETHODIMP CGlobalSettings::put_ClipperGcsMultiplicationFactor(const DOUBLE newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.clipperGcsMultiplicationFactor = newVal;
	return S_OK;
}

// ****************************************************
//	    CreatePoint()
// ****************************************************
STDMETHODIMP CGlobalSettings::CreatePoint(IPoint** retVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	ComHelper::CreatePoint(retVal);
	return S_OK;
}

// ****************************************************
//	    get_ShapefileFastMode()
// ****************************************************
STDMETHODIMP CGlobalSettings::get_ShapefileFastMode(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = m_globalSettings.shapefileFastMode ? VARIANT_TRUE : VARIANT_FALSE;
	return S_OK;
}

// ****************************************************
//	    put_ShapefileFastMode()
// ****************************************************
STDMETHODIMP CGlobalSettings::put_ShapefileFastMode(const VARIANT_BOOL newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.shapefileFastMode = newVal == VARIANT_FALSE ? false : true;
	return S_OK;
}

// ****************************************************
//	    get_ShapefileFastMode()
// ****************************************************
STDMETHODIMP CGlobalSettings::get_ZoomToFirstLayer(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = m_globalSettings.zoomToFirstLayer ? VARIANT_TRUE : VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CGlobalSettings::put_ZoomToFirstLayer(const VARIANT_BOOL newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.zoomToFirstLayer = newVal == VARIANT_FALSE ? false : true;
	return S_OK;
}

// ****************************************************
//	    get_LabelCollisionMode()
// ****************************************************
STDMETHODIMP CGlobalSettings::get_LabelsCollisionMode(tkCollisionMode* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = m_globalSettings.labelsCollisionMode;
	return S_OK;
}

STDMETHODIMP CGlobalSettings::put_LabelsCollisionMode(const tkCollisionMode newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.labelsCollisionMode = newVal;
	return S_OK;
}


// ****************************************************
//	    get_InvalidShapesBufferDistance()
// ****************************************************
STDMETHODIMP CGlobalSettings::get_InvalidShapesBufferDistance(DOUBLE* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = m_globalSettings.invalidShapesBufferDistance;
	return S_OK;
}

// ****************************************************
//	    put_InvalidShapesBufferDistance()
// ****************************************************
STDMETHODIMP CGlobalSettings::put_InvalidShapesBufferDistance(const DOUBLE newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.invalidShapesBufferDistance = newVal;
	return S_OK;
}

// ****************************************************
//	    get_ShapefileFastUnion()
// ****************************************************
STDMETHODIMP CGlobalSettings::get_ShapefileFastUnion(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = m_globalSettings.shapefileFastUnion ? VARIANT_TRUE : VARIANT_FALSE;
	return S_OK;
}

// ****************************************************
//	    put_ShapefileFastUnion()
// ****************************************************
STDMETHODIMP CGlobalSettings::put_ShapefileFastUnion(const VARIANT_BOOL newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.shapefileFastUnion = newVal == VARIANT_FALSE ? false : true;
	return S_OK;
}

#pragma region "Gdal error handling"
// ****************************************************
//	    get_GdalLastErrorNo()
// ****************************************************
STDMETHODIMP CGlobalSettings::get_GdalLastErrorNo(tkGdalError* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	int err = CPLGetLastErrorNo();
	if (err < 0 || err >= static_cast<int>(GdalErrorUndefined))
		err = static_cast<int>(GdalErrorUndefined);

	*pVal = static_cast<tkGdalError>(err);
	return S_OK;
}

// ****************************************************
//	    get_GdalLastErrorType()
// ****************************************************
STDMETHODIMP CGlobalSettings::get_GdalLastErrorType(tkGdalErrorType* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	int err = CPLGetLastErrorType();
	if (err < 0 || err >= static_cast<int>(GdalUndefined))
		err = static_cast<int>(GdalUndefined);

	*pVal = static_cast<tkGdalErrorType>(err);
	return S_OK;
}

// ****************************************************
//	    get_GdalLastErrorMsg()
// ****************************************************
STDMETHODIMP CGlobalSettings::get_GdalLastErrorMsg(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	const CString s = CPLGetLastErrorMsg();
	*pVal = A2BSTR(s);
	return S_OK;
}

// ****************************************************
//	    get_GdalReprojectionErrorMsg()
// ****************************************************
STDMETHODIMP CGlobalSettings::get_GdalReprojectionErrorMsg(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = A2BSTR(m_globalSettings.gdalErrorMessage);
	return S_OK;
}

// ****************************************************
//	    ResetGdalError()
// ****************************************************
STDMETHODIMP CGlobalSettings::ResetGdalError()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CPLErrorReset();
	m_globalSettings.gdalErrorMessage = "";
	return S_OK;
}
#pragma endregion

#pragma region Labels

// ****************************************************
//	    get_CompositingQuality()
// ****************************************************
STDMETHODIMP CGlobalSettings::get_LabelsCompositingQuality(tkCompositingQuality* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = m_globalSettings.labelsCompositingQuality;
	return S_OK;
}

// ****************************************************
//	    put_CompositingQuality()
// ****************************************************
STDMETHODIMP CGlobalSettings::put_LabelsCompositingQuality(const tkCompositingQuality newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (newVal >= 0 && newVal <= AssumeLinear)
		m_globalSettings.labelsCompositingQuality = newVal;
	return S_OK;
}

// ****************************************************
//	    get_SmoothingMode()
// ****************************************************
STDMETHODIMP CGlobalSettings::get_LabelsSmoothingMode(tkSmoothingMode* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = m_globalSettings.labelsSmoothingMode;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_LabelsSmoothingMode(const tkSmoothingMode newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	if (newVal >= 0 && newVal <= AntiAlias)
		m_globalSettings.labelsSmoothingMode = newVal;
	return S_OK;
}
#pragma endregion

// ****************************************************
//	    LocalizedString()
// ****************************************************
STDMETHODIMP CGlobalSettings::put_LocalizedString(const tkLocalizedStrings unit, BSTR localizedString)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.shortUnitStrings[unit] = CStringW(localizedString);
	return S_OK;
}
STDMETHODIMP CGlobalSettings::get_LocalizedString(const tkLocalizedStrings unit, BSTR* retVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	const CStringW s = m_globalSettings.GetLocalizedString(unit);
	*retVal = W2BSTR(s);
	return S_OK;
}

// ****************************************************
//	    GridProxyFormat()
// ****************************************************
STDMETHODIMP CGlobalSettings::get_GridProxyFormat(tkGridProxyFormat* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = m_globalSettings.gridProxyFormat;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_GridProxyFormat(const tkGridProxyFormat newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.gridProxyFormat = newVal;
	return S_OK;
}

// ****************************************************
//	    MaxDirectGridSizeMb()
// ****************************************************
STDMETHODIMP CGlobalSettings::get_MaxDirectGridSizeMb(double* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = m_globalSettings.MaxDirectGridSizeMb;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_MaxDirectGridSizeMb(const double newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.MaxDirectGridSizeMb = newVal;
	return S_OK;
}

// ****************************************************
//	    get_AlwaysCreateProxyForGrids()
// ****************************************************
STDMETHODIMP CGlobalSettings::get_GridProxyMode(tkGridProxyMode* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = m_globalSettings.gridProxyMode;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_GridProxyMode(const tkGridProxyMode newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.gridProxyMode = newVal;
	return S_OK;
}

// ****************************************************
//	    get_MaxUniqueValuesCountForGridScheme()
// ****************************************************
STDMETHODIMP CGlobalSettings::get_MaxUniqueValuesCountForGridScheme(int* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = m_globalSettings.maxUniqueValuesCount;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_MaxUniqueValuesCountForGridScheme(const int newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.maxUniqueValuesCount = newVal;
	return S_OK;
}

// ****************************************************
//	    RandomColorSchemeForGrids()
// ****************************************************
STDMETHODIMP CGlobalSettings::get_RandomColorSchemeForGrids(VARIANT_BOOL* retVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*retVal = m_globalSettings.randomColorSchemeForGrids ? VARIANT_TRUE : VARIANT_FALSE;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_RandomColorSchemeForGrids(const VARIANT_BOOL newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.randomColorSchemeForGrids = newVal == VARIANT_FALSE ? false : true;;
	return S_OK;
}

// ****************************************************
//	    DefaultColorSchemeForGrids()
// ****************************************************
STDMETHODIMP CGlobalSettings::get_DefaultColorSchemeForGrids(PredefinedColorScheme* retVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*retVal = m_globalSettings.defaultColorSchemeForGrids;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_DefaultColorSchemeForGrids(const PredefinedColorScheme newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.defaultColorSchemeForGrids = newVal;
	return S_OK;
}

// ****************************************************
//	    ShapeOutputValidationMode
// ****************************************************
STDMETHODIMP CGlobalSettings::get_ShapeOutputValidationMode(tkShapeValidationMode* retVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*retVal = m_globalSettings.outputValidation;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_ShapeOutputValidationMode(const tkShapeValidationMode newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.outputValidation = newVal;
	return S_OK;
}

// ****************************************************
//	    ShapeInputValidationMode
// ****************************************************
STDMETHODIMP CGlobalSettings::get_ShapeInputValidationMode(tkShapeValidationMode* retVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*retVal = m_globalSettings.inputValidation;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_ShapeInputValidationMode(const tkShapeValidationMode newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.inputValidation = newVal;
	return S_OK;
}

// ****************************************************
//	    GeometryEngine
// ****************************************************
STDMETHODIMP CGlobalSettings::get_GeometryEngine(tkGeometryEngine* retVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*retVal = m_globalSettings.geometryEngine;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_GeometryEngine(const tkGeometryEngine newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.geometryEngine = newVal;
	return S_OK;
}

// ****************************************************
//	    SaveGridColorSchemeToFile
// ****************************************************
STDMETHODIMP CGlobalSettings::get_SaveGridColorSchemeToFile(VARIANT_BOOL* retVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*retVal = m_globalSettings.saveGridColorSchemeToFile ? VARIANT_TRUE : VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CGlobalSettings::put_SaveGridColorSchemeToFile(const VARIANT_BOOL newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.saveGridColorSchemeToFile = newVal == VARIANT_FALSE ? false : true;
	return S_OK;
}

// ****************************************************
//	    TiffCompression
// ****************************************************
STDMETHODIMP CGlobalSettings::get_TiffCompression(tkTiffCompression* retVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*retVal = m_globalSettings.tiffCompression;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_TiffCompression(const tkTiffCompression newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.tiffCompression = newVal;
	return S_OK;
}

// ****************************************************
//	    RasterOverviewCreation
// ****************************************************
STDMETHODIMP CGlobalSettings::get_RasterOverviewCreation(tkRasterOverviewCreation* retVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*retVal = m_globalSettings.rasterOverviewCreation;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_RasterOverviewCreation(const tkRasterOverviewCreation newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.rasterOverviewCreation = newVal;
	return S_OK;
}

// ****************************************************
//	    MinOverviewWidth
// ****************************************************
STDMETHODIMP CGlobalSettings::get_MinOverviewWidth(int* retVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*retVal = m_globalSettings.minOverviewWidth;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_MinOverviewWidth(const int newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.minOverviewWidth = newVal;
	return S_OK;
}

// ****************************************************
//	    RasterOverviewResampling
// ****************************************************
STDMETHODIMP CGlobalSettings::get_RasterOverviewResampling(tkGDALResamplingMethod* retVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*retVal = m_globalSettings.rasterOverviewResampling;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_RasterOverviewResampling(const tkGDALResamplingMethod newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.rasterOverviewResampling = newVal;
	return S_OK;
}

// *********************************************************
//	     TilesThreadPoolSize
// *********************************************************
STDMETHODIMP CGlobalSettings::get_TilesThreadPoolSize(int* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = m_globalSettings.tilesThreadPoolSize;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_TilesThreadPoolSize(const int newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.tilesThreadPoolSize = newVal;
	return S_OK;
}

// *********************************************************
//	     LoadSymbologyOnAddLayer
// *********************************************************
STDMETHODIMP CGlobalSettings::get_LoadSymbologyOnAddLayer(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = m_globalSettings.loadSymbologyOnAddLayer;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_LoadSymbologyOnAddLayer(const VARIANT_BOOL newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.loadSymbologyOnAddLayer = newVal == VARIANT_FALSE ? false : true;
	return S_OK;
}

// *********************************************************
//	     TilesMinZoomOnProjectionMismatch
// *********************************************************
STDMETHODIMP CGlobalSettings::get_TilesMinZoomOnProjectionMismatch(int* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = m_globalSettings.tilesMaxZoomOnProjectionMismatch;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_TilesMinZoomOnProjectionMismatch(const int newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.tilesMaxZoomOnProjectionMismatch = newVal;
	return S_OK;
}


// *********************************************************
//	     ImageUpsamplingMode
// *********************************************************
STDMETHODIMP CGlobalSettings::get_ImageUpsamplingMode(tkInterpolationMode* newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*newVal = m_globalSettings.imageUpsamplingMode;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_ImageUpsamplingMode(const tkInterpolationMode newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.imageUpsamplingMode = newVal;
	return S_OK;
}

// *********************************************************
//	     ImageDownsamplingMode
// *********************************************************
STDMETHODIMP CGlobalSettings::get_ImageDownsamplingMode(tkInterpolationMode* newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*newVal = m_globalSettings.imageDownsamplingMode;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_ImageDownsamplingMode(const tkInterpolationMode newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.imageDownsamplingMode = newVal;
	return S_OK;
}

// *********************************************************
//	     GridUpsamplingMode
// *********************************************************
STDMETHODIMP CGlobalSettings::get_GridUpsamplingMode(tkInterpolationMode* newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*newVal = m_globalSettings.gridUpsamplingMode;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_GridUpsamplingMode(const tkInterpolationMode newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.gridUpsamplingMode = newVal;
	return S_OK;
}

// *********************************************************
//	     GridDownsamplingMode
// *********************************************************
STDMETHODIMP CGlobalSettings::get_GridDownsamplingMode(tkInterpolationMode* newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*newVal = m_globalSettings.gridDownsamplingMode;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_GridDownsamplingMode(const tkInterpolationMode newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.gridDownsamplingMode = newVal;
	return S_OK;
}

// *********************************************************
//	     OgrStringEncoding
// *********************************************************
STDMETHODIMP CGlobalSettings::get_OgrStringEncoding(tkOgrEncoding* newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*newVal = m_globalSettings.ogrEncoding;
	return S_OK;
}

STDMETHODIMP CGlobalSettings::put_OgrStringEncoding(const tkOgrEncoding pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.ogrEncoding = pVal;
	return S_OK;
}

// *********************************************************
//	     OgrLayerMaxFeatureCount
// *********************************************************
STDMETHODIMP CGlobalSettings::get_OgrLayerMaxFeatureCount(LONG* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = m_globalSettings.ogrLayerMaxFeatureCount;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_OgrLayerMaxFeatureCount(const LONG newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.ogrLayerMaxFeatureCount = newVal;
	return S_OK;
}

// *********************************************************
//	     AutoChooseOgrLoadingMode
// *********************************************************
STDMETHODIMP CGlobalSettings::get_AutoChooseOgrLoadingMode(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = m_globalSettings.autoChooseOgrLoadingMode ? VARIANT_TRUE : VARIANT_FALSE;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_AutoChooseOgrLoadingMode(const VARIANT_BOOL newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.autoChooseOgrLoadingMode = newVal == VARIANT_FALSE ? false : true;
	return S_OK;
}

// *********************************************************
//	     AttachMapCallbackToLayers
// *********************************************************
STDMETHODIMP CGlobalSettings::get_AttachMapCallbackToLayers(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = m_globalSettings.attachMapCallbackToLayers ? VARIANT_TRUE : VARIANT_FALSE;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_AttachMapCallbackToLayers(const VARIANT_BOOL newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.attachMapCallbackToLayers = newVal == VARIANT_FALSE ? false : true;
	return S_OK;
}

// *********************************************************
//	     HotTrackingMaxShapeCount
// *********************************************************
STDMETHODIMP CGlobalSettings::get_HotTrackingMaxShapeCount(LONG* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = m_globalSettings.hotTrackingMaxShapeCount;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_HotTrackingMaxShapeCount(const LONG newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.hotTrackingMaxShapeCount = newVal;
	return S_OK;
}

// *********************************************************
//	     AllowLayersWithoutProjections
// *********************************************************
STDMETHODIMP CGlobalSettings::get_AllowLayersWithoutProjections(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = m_globalSettings.allowLayersWithoutProjection ? VARIANT_TRUE : VARIANT_FALSE;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_AllowLayersWithoutProjections(const VARIANT_BOOL newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.allowLayersWithoutProjection = newVal == VARIANT_FALSE ? false : true;
	return S_OK;
}

// *********************************************************
//	     AllowProjectionMismatch
// *********************************************************
STDMETHODIMP CGlobalSettings::get_AllowProjectionMismatch(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = m_globalSettings.allowProjectionMismatch ? VARIANT_TRUE : VARIANT_FALSE;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_AllowProjectionMismatch(const VARIANT_BOOL newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.allowProjectionMismatch = newVal == VARIANT_FALSE ? false : true;
	return S_OK;
}

// *********************************************************
//	     ReprojectLayersOnAdding
// *********************************************************
STDMETHODIMP CGlobalSettings::get_ReprojectLayersOnAdding(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = m_globalSettings.reprojectLayersOnAdding ? VARIANT_TRUE : VARIANT_FALSE;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_ReprojectLayersOnAdding(const VARIANT_BOOL newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.reprojectLayersOnAdding = newVal == VARIANT_FALSE ? false : true;
	return S_OK;
}

// *********************************************************
//	     MouseTolerance
// *********************************************************
STDMETHODIMP CGlobalSettings::get_MouseTolerance(DOUBLE* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = m_globalSettings.mouseTolerance;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_MouseTolerance(const DOUBLE newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.mouseTolerance = newVal;
	return S_OK;
}

// *********************************************************
//	     ApplicationCallback
// *********************************************************
STDMETHODIMP CGlobalSettings::get_ApplicationCallback(ICallback** pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = m_globalSettings.callback;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_ApplicationCallback(ICallback* newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	ComHelper::SetRef(newVal, (IDispatch**)&m_globalSettings.callback); // TODO: Fix compile warning
	return S_OK;
}

// *********************************************************
//	     MaxReprojectionShapeCount
// *********************************************************
STDMETHODIMP CGlobalSettings::get_MaxReprojectionShapeCount(LONG* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = m_globalSettings.maxReprojectionShapeCount;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_MaxReprojectionShapeCount(const LONG newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.maxReprojectionShapeCount = newVal;
	return S_OK;
}

// *********************************************************
//	     PixelOffsetMode
// *********************************************************
STDMETHODIMP CGlobalSettings::get_PixelOffsetMode(tkPixelOffsetMode* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = m_globalSettings.pixelOffsetMode;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_PixelOffsetMode(const tkPixelOffsetMode newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.pixelOffsetMode = newVal;
	return S_OK;
}

// *********************************************************
//	     AutoChooseRenderingHintForLabels
// *********************************************************
STDMETHODIMP CGlobalSettings::get_AutoChooseRenderingHintForLabels(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = m_globalSettings.autoChooseRenderingHintForLabels ? VARIANT_TRUE : VARIANT_FALSE;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_AutoChooseRenderingHintForLabels(const VARIANT_BOOL newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.autoChooseRenderingHintForLabels = newVal == VARIANT_FALSE ? false : true;
	return S_OK;
}

// ***************************************************************
//	get_GdalVersion
// ***************************************************************
STDMETHODIMP CGlobalSettings::get_GdalVersion(BSTR* retVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	const CComBSTR bstr("");
	const CComBSTR bstrOptions("--version");
	// TODO: Update to GDALUtils ??
	GetUtils()->GDALInfo(bstr, bstrOptions, nullptr, retVal);
	return S_OK;
}

// ***************************************************************
//	OgrLayerForceUpdateMode
// ***************************************************************
STDMETHODIMP CGlobalSettings::get_OgrLayerForceUpdateMode(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = m_globalSettings.ogrLayerForceUpdateMode ? VARIANT_TRUE : VARIANT_FALSE;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_OgrLayerForceUpdateMode(const VARIANT_BOOL newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.ogrLayerForceUpdateMode = newVal == VARIANT_FALSE ? false : true;
	return S_OK;
}

// ***************************************************************
//		ForceHideLabels
// ***************************************************************
STDMETHODIMP CGlobalSettings::get_ForceHideLabels(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = m_globalSettings.forceHideLabels ? VARIANT_TRUE : VARIANT_FALSE;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_ForceHideLabels(const VARIANT_BOOL newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.forceHideLabels = newVal == VARIANT_FALSE ? false : true;
	return S_OK;
}

// ***************************************************************
//		GdalPluginPath
// ***************************************************************
STDMETHODIMP CGlobalSettings::get_GdalPluginPath(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	const CStringW path = GdalHelper::GetConfigPath(PathGdalPlugins);
	*pVal = W2BSTR(path);
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_GdalPluginPath(BSTR newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	GdalHelper::SetConfigPath(PathGdalPlugins, CStringW(newVal));
	return S_OK;
}

// ***************************************************************
//		GdalDataPath
// ***************************************************************
STDMETHODIMP CGlobalSettings::get_GdalDataPath(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	const CStringW path = GdalHelper::GetConfigPath(PathGdalData);
	*pVal = W2BSTR(path);
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_GdalDataPath(BSTR newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	GdalHelper::SetConfigPath(PathGdalData, CStringW(newVal));
	return S_OK;
}
// ***************************************************************
//		PROJ.7 path
// ***************************************************************
STDMETHODIMP CGlobalSettings::get_ProjPath(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	const CStringW path = GdalHelper::GetConfigPath(PathProjLib);
	*pVal = W2BSTR(path);
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_ProjPath(BSTR newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	GdalHelper::SetConfigPath(PathProjLib, CStringW(newVal));
	return S_OK;
}

// ***************************************************************
//		BingApiKey
// ***************************************************************
STDMETHODIMP CGlobalSettings::get_BingApiKey(BSTR* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*pVal = A2BSTR(m_globalSettings.bingApiKey);
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_BingApiKey(BSTR newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	//m_globalSettings.bingApiKey = OLE2A(newVal);
	m_globalSettings.bingApiKey = CString(newVal);
	return S_OK;
}

// ***************************************************************
//		TestBingApiKey
// ***************************************************************
STDMETHODIMP CGlobalSettings::TestBingApiKey(BSTR apiKey, VARIANT_BOOL* retVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*retVal = VARIANT_FALSE;

	const CString previousKey = m_globalSettings.bingApiKey;
	m_globalSettings.bingApiKey = CString(apiKey);

	BingMapProvider provider;
	if (provider.Initialize()) {
		m_globalSettings.bingApiKey = apiKey;
		*retVal = VARIANT_TRUE;
	}
	else {
		m_globalSettings.bingApiKey = previousKey;
	}

	return S_OK;
}

// ***************************************************************
//		SetHereMapsApiKey
// ***************************************************************
STDMETHODIMP CGlobalSettings::SetHereMapsApiKey(BSTR appId, BSTR appCode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	m_globalSettings.hereAppCode = CString(appCode);
	m_globalSettings.hereAppId = CString(appId);
	return S_OK;
}

// ***************************************************************
//		CompressOverviews
// ***************************************************************
STDMETHODIMP CGlobalSettings::get_CompressOverviews(tkTiffCompression* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	const CString s = "";
	const CString value = CPLGetConfigOption("COMPRESS_OVERVIEW", s);
	*pVal = GdalHelper::ParseTiffCompression(value);

	return S_OK;
}

STDMETHODIMP CGlobalSettings::put_CompressOverviews(const tkTiffCompression newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	const CString s = GdalHelper::TiffCompressionToString(newVal);

	CPLSetConfigOption("COMPRESS_OVERVIEW", s);

	return S_OK;
}

// ***************************************************************
//		GridFavorGreyscale
// ***************************************************************
STDMETHODIMP CGlobalSettings::get_GridFavorGreyscale(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	*pVal = m_globalSettings.gridFavorGreyScale ? VARIANT_TRUE : VARIANT_FALSE;

	return S_OK;
}

STDMETHODIMP CGlobalSettings::put_GridFavorGreyscale(const VARIANT_BOOL newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_globalSettings.gridFavorGreyScale = newVal == VARIANT_FALSE ? false : true;

	return S_OK;
}

// ***************************************************************
//		GridUseHistogram
// ***************************************************************
STDMETHODIMP CGlobalSettings::get_GridUseHistogram(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	*pVal = m_globalSettings.gridUseHistogram ? VARIANT_TRUE : VARIANT_FALSE;

	return S_OK;
}

STDMETHODIMP CGlobalSettings::put_GridUseHistogram(const VARIANT_BOOL newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_globalSettings.gridUseHistogram = newVal == VARIANT_FALSE ? false : true;

	return S_OK;
}

// ***************************************************************
//		OverrideLocalCallback
// ***************************************************************
STDMETHODIMP CGlobalSettings::get_OverrideLocalCallback(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	*pVal = m_globalSettings.overrideLocalCallback ? VARIANT_TRUE : VARIANT_FALSE;

	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_OverrideLocalCallback(const VARIANT_BOOL newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_globalSettings.overrideLocalCallback = newVal == VARIANT_FALSE ? false : true;

	return S_OK;
}

// ***************************************************************
//		CacheDbfRecords
// ***************************************************************
STDMETHODIMP CGlobalSettings::get_CacheDbfRecords(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	*pVal = m_globalSettings.cacheDbfRecords;

	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_CacheDbfRecords(const VARIANT_BOOL newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_globalSettings.cacheDbfRecords = newVal == VARIANT_FALSE ? false : true;

	return S_OK;
}

// ***************************************************************
//		CacheShapeRenderingData
// ***************************************************************
STDMETHODIMP CGlobalSettings::get_CacheShapeRenderingData(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	*pVal = m_globalSettings.cacheShapeRenderingData;

	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_CacheShapeRenderingData(const VARIANT_BOOL newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_globalSettings.cacheShapeRenderingData = newVal == VARIANT_FALSE ? false : true;

	return S_OK;
}

// *********************************************************
//	     LogErrorsOnly()
// *********************************************************
STDMETHODIMP CGlobalSettings::get_LogTileErrorsOnly(VARIANT_BOOL* retVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())
		* retVal = tilesLogger.errorsOnly;
	return S_OK;
}
STDMETHODIMP CGlobalSettings::put_LogTileErrorsOnly(const VARIANT_BOOL newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())
		tilesLogger.errorsOnly = newVal == VARIANT_FALSE ? false : true;
	return S_OK;
}

// *********************************************************
//	     StartLogRequests()
// *********************************************************
STDMETHODIMP CGlobalSettings::StartLogTileRequests(BSTR filename, const VARIANT_BOOL errorsOnly, VARIANT_BOOL* retVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	const CStringW path(filename);
	tilesLogger.Open(path);
	tilesLogger.errorsOnly = errorsOnly == VARIANT_FALSE ? false : true;
	*retVal = tilesLogger.IsOpened();
	return S_OK;
}

// *********************************************************
//	     StopLogRequests()
// *********************************************************
STDMETHODIMP CGlobalSettings::StopLogTileRequests()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	tilesLogger.Close();
	return S_OK;
}

// *********************************************************
//	     LogIsOpened()
// *********************************************************
STDMETHODIMP CGlobalSettings::get_TileLogIsOpened(VARIANT_BOOL* retVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*retVal = tilesLogger.IsOpened();
	return S_OK;
}

// *********************************************************
//	     LogFilename()
// *********************************************************
STDMETHODIMP CGlobalSettings::get_TileLogFilename(BSTR* retVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	*retVal = W2BSTR(tilesLogger.GetFilename());
	return S_OK;
}

STDMETHODIMP CGlobalSettings::SetHttpUserAgent(BSTR userAgent)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	// TODO: Check if not string.empty
	m_globalSettings.httpUserAgent = CString(userAgent);
	return S_OK;
}

// *********************************************************
//	     WmsDiskCaching()
// *********************************************************
STDMETHODIMP CGlobalSettings::get_WmsDiskCaching(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	*pVal = m_globalSettings.wmsDiskCaching ? VARIANT_TRUE : VARIANT_FALSE;

	return S_OK;
}

STDMETHODIMP CGlobalSettings::put_WmsDiskCaching(const VARIANT_BOOL newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_globalSettings.wmsDiskCaching = newVal == VARIANT_FALSE ? false : true;

	return S_OK;
}

// *********************************************************
//	     CallbackVerbosity()
// *********************************************************
STDMETHODIMP CGlobalSettings::get_CallbackVerbosity(tkCallbackVerbosity* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	*pVal = m_globalSettings.callbackVerbosity;

	return S_OK;
}

STDMETHODIMP CGlobalSettings::put_CallbackVerbosity(const tkCallbackVerbosity newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_globalSettings.callbackVerbosity = newVal;

	return S_OK;
}

// *********************************************************
//	     OgrShareConnection()
// *********************************************************
STDMETHODIMP CGlobalSettings::get_OgrShareConnection(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	*pVal = m_globalSettings.ogrShareConnection ? VARIANT_TRUE : VARIANT_FALSE;

	return S_OK;
}

STDMETHODIMP CGlobalSettings::put_OgrShareConnection(const VARIANT_BOOL newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_globalSettings.ogrShareConnection = newVal == VARIANT_FALSE ? false : true;

	return S_OK;
}

// *********************************************************
//	     OgrInterpretYNStringAsBoolean()
// *********************************************************
STDMETHODIMP CGlobalSettings::get_OgrInterpretYNStringAsBoolean(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	*pVal = m_globalSettings.ogrInterpretYNStringAsBoolean ? VARIANT_TRUE : VARIANT_FALSE;

	return S_OK;
}

STDMETHODIMP CGlobalSettings::put_OgrInterpretYNStringAsBoolean(const VARIANT_BOOL newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_globalSettings.ogrInterpretYNStringAsBoolean = newVal == VARIANT_FALSE ? false : true;

	return S_OK;
}

// *********************************************************
//	     AllowLayersWithIncompleteReprojection()
// *********************************************************
STDMETHODIMP CGlobalSettings::get_AllowLayersWithIncompleteReprojection(VARIANT_BOOL* pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	*pVal = m_globalSettings.allowLayersWithIncompleteReprojection ? VARIANT_TRUE : VARIANT_FALSE;

	return S_OK;
}

STDMETHODIMP CGlobalSettings::put_AllowLayersWithIncompleteReprojection(const VARIANT_BOOL newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	m_globalSettings.allowLayersWithIncompleteReprojection = newVal == VARIANT_FALSE ? false : true;

	return S_OK;
}
