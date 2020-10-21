/*=========================================================================
 *
 *  Copyright UMC Utrecht and contributors
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#ifndef __itkGPUAdvancedBSplineDeformableTransformFactory_h
#define __itkGPUAdvancedBSplineDeformableTransformFactory_h

#include "itkGPUObjectFactoryBase.h"
#include "itkGPUAdvancedBSplineDeformableTransform.h"

namespace itk
{
/** \class GPUAdvancedBSplineDeformableTransformFactory
 * \brief Object Factory implementation for GPUAdvancedBSplineDeformableTransform
 *
 * \author Denis P. Shamonin and Marius Staring. Division of Image Processing,
 * Department of Radiology, Leiden, The Netherlands
 *
 * \note This work was funded by the Netherlands Organisation for
 * Scientific Research (NWO NRG-2010.02 and NWO 639.021.124).
 *
 */
template <typename NDimensions>
class GPUAdvancedBSplineDeformableTransformFactory2 : public GPUObjectFactoryBase<NDimensions>
{
public:
  typedef GPUAdvancedBSplineDeformableTransformFactory2 Self;
  typedef GPUObjectFactoryBase<NDimensions>             Superclass;
  typedef SmartPointer<Self>                            Pointer;
  typedef SmartPointer<const Self>                      ConstPointer;

  /** Return a descriptive string describing the factory. */
  const char *
  GetDescription() const
  {
    return "A Factory for GPUAdvancedBSplineDeformableTransform";
  }

  /** Method for class instantiation. */
  itkFactorylessNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(GPUAdvancedBSplineDeformableTransformFactory2, GPUObjectFactoryBase);

  /** Register one factory of this type. */
  static void
  RegisterOneFactory();

  /** Operator() to register override. */
  template <typename TType, unsigned int VImageDimension>
  void
  operator()(void)
  {
    // Override for spline order equal 1
    this->RegisterOverride(
      typeid(AdvancedBSplineDeformableTransform<TType, VImageDimension, 1>).name(),
      typeid(GPUAdvancedBSplineDeformableTransform<TType, VImageDimension, 1>).name(),
      "GPU AdvancedBSplineDeformableTransform override, spline order 1",
      true,
      CreateObjectFunction<GPUAdvancedBSplineDeformableTransform<TType, VImageDimension, 1>>::New());

    // Override for spline order equal 2
    this->RegisterOverride(
      typeid(AdvancedBSplineDeformableTransform<TType, VImageDimension, 2>).name(),
      typeid(GPUAdvancedBSplineDeformableTransform<TType, VImageDimension, 2>).name(),
      "GPU AdvancedBSplineDeformableTransform override, spline order 2",
      true,
      CreateObjectFunction<GPUAdvancedBSplineDeformableTransform<TType, VImageDimension, 2>>::New());

    // Override for spline order equal 3
    this->RegisterOverride(
      typeid(AdvancedBSplineDeformableTransform<TType, VImageDimension, 3>).name(),
      typeid(GPUAdvancedBSplineDeformableTransform<TType, VImageDimension, 3>).name(),
      "GPU AdvancedBSplineDeformableTransform override, spline order 3",
      true,
      CreateObjectFunction<GPUAdvancedBSplineDeformableTransform<TType, VImageDimension, 3>>::New());
  }


protected:
  GPUAdvancedBSplineDeformableTransformFactory2();
  virtual ~GPUAdvancedBSplineDeformableTransformFactory2() {}

  /** Typedef for real type list. */
  typedef typelist::MakeTypeList<float, double>::Type RealTypeList;

  /** Register methods for 1D. */
  virtual void
  Register1D();

  /** Register methods for 2D. */
  virtual void
  Register2D();

  /** Register methods for 3D. */
  virtual void
  Register3D();

private:
  GPUAdvancedBSplineDeformableTransformFactory2(const Self &); // purposely not implemented
  void
  operator=(const Self &); // purposely not implemented
};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#  include "itkGPUAdvancedBSplineDeformableTransformFactory.hxx"
#endif

#endif /* __itkGPUAdvancedBSplineDeformableTransformFactory_h */
