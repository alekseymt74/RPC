#ifndef _TypedefTestIMPL_H_
#define _TypedefTestIMPL_H_

/** 
 * Generated by DDSCS: Do not edit.  Version 1.0 *
 */

#include "utils/DDSCSMessages.h"
#include "TypedefTestRequestReplyUtils.h"

class TypedefTestImpl
{
    public:

        /// \brief The default constructor.
        TypedefTestImpl();

        /// \brief The default destructor.
        virtual ~TypedefTestImpl();

         
        DDSCSMessages
         getLargo(largo l1 ,largo &l2, largo &getLargo_ret);
         
        DDSCSMessages
         getLarguisimo(larguisimo ll1 ,larguisimo &ll2, larguisimo &getLarguisimo_ret);
         
        DDSCSMessages
         getDatosDef(DatosDef & d1 ,DatosDef  &d2, DatosDef  &getDatosDef_ret);
         
        DDSCSMessages
         getDatosDefondo(DatosDefondo & dd1 ,DatosDefondo  &dd2, DatosDefondo  &getDatosDefondo_ret);
         
        DDSCSMessages
         getCadena(cadena c1 ,cadena &c2, cadena &getCadena_ret);
         
        DDSCSMessages
         getCorrea(correa cc1 ,correa &cc2, correa &getCorrea_ret);
};

#endif // _TypedefTestIMPL_H_