// -*- C++ -*-
// $Id: prec_dwf_fermact_base_array_w.h,v 1.1 2003-11-22 21:34:01 edwards Exp $
/*! \file
 *  \brief Base class for even-odd preconditioned domain-wall-like fermion actions
 */

#ifndef __prec_dwf_fermact_base_array_w_h__
#define __prec_dwf_fermact_base_array_w_h__

#include "fermact_array.h"

using namespace QDP;

//! Base class for unpreconditioned domain-wall-like fermion actions
/*! \ingroup fermact
 *
 * Unprecondition domain-wall fermion action. The conventions used here
 * are specified in Phys.Rev.D63:094505,2001 (hep-lat/0005002).
 */

//class EvenOddPrecDWFermActBaseArray : public EvenOddPrecWilsonTypeFermActArray<LatticeFermion>
class EvenOddPrecDWFermActBaseArray : public WilsonTypeFermActArray<LatticeFermion>
{
public:
  //! Return the quark mass
  virtual Real quark_mass() const = 0;

  //! Produce a linear operator for this action
  virtual const LinearOperator< multi1d<LatticeFermion> >* evenEvenInvLinOp(const multi1d<LatticeColorMatrix>& u) const = 0;

  //! Produce a linear operator for this action
  virtual const LinearOperator< multi1d<LatticeFermion> >* evenOddLinOp(const multi1d<LatticeColorMatrix>& u) const = 0;

  //! Produce a linear operator for this action
  virtual const LinearOperator< multi1d<LatticeFermion> >* oddEvenLinOp(const multi1d<LatticeColorMatrix>& u) const = 0;

  //! Produce a linear operator for this action
  virtual const LinearOperator< multi1d<LatticeFermion> >* oddOddLinOp(const multi1d<LatticeColorMatrix>& u) const = 0;

  //! Produce a linear operator for this action
  virtual const LinearOperator< multi1d<LatticeFermion> >* linOp(const multi1d<LatticeColorMatrix>& u) const = 0;

  //! Produce a linear operator M^dag.M for this action
  virtual const LinearOperator< multi1d<LatticeFermion> >* lMdagM(const multi1d<LatticeColorMatrix>& u) const = 0;

  //! Produce a linear operator for this action but with quark mass 1
  virtual const LinearOperator< multi1d<LatticeFermion> >* linOpPV(const multi1d<LatticeColorMatrix>& u) const = 0;

  //! Define quark propagator routine for 4D fermions
  void qprop(LatticeFermion& psi, 
	     const multi1d<LatticeColorMatrix>& u, 
	     const LatticeFermion& chi, 
	     enum InvType invType,
	     const Real& RsdCG, 
	     int MaxCG, int& ncg_had) const;

  //! Compute dS_f/dU
  void dsdu(multi1d<LatticeColorMatrix>& result,
	    const multi1d<LatticeColorMatrix>& u,
	    const multi1d<LatticeFermion>& psi) const;
};

#endif
